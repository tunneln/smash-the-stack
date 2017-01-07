# Smash The Stack

A demonstration of a buffer overflow attack on a simple
program via "smashing the stack", in order to execute a foreign processess/code.

### To run:
* `$ source setup.sh`
* `$ make && make run`

## How my attack works

tl;dr The attack overwrites the return address of the stack frame to some "illegal" execution
(spawns/execv a new shell) so that it may be called and run.

#### Details

A simple 45-byte program is written into the buffer, preceded by a NOP slide.
The return address of main is overwritten to jump to the beginning of the NOP
slide, which runs the 45-byte program which spawns a shell.

The return address is stored in &buf[272] in main. The expected address was
&buf[264]. However, the actual address was different. This could possibly be attributed to page alignment.
NOTE: &buf[260] stores EBP and &buf[264] stores the return address

In exploit.c, I find the head address of the stack [parameters] and
dynamically overwrite the end of the stack with this address (where the return pointer
is located).

An important point to note is that I had to turn off random stack allocation,
which is normally intended to protect from these types of attacks, by calling
`$source setup.sh`.
This way the exploit can mantain consistentncy between systems
despite changes in the address spaces.


**NOTE:** Tested on an intel/x86_64 ISA (Little Endian) in GNU/Linux 3.13.0-105
