all:
	gcc -o exploit exploit.c -m32 -z execstack -std=c99 -O0 -fno-stack-protector
	gcc -o main main.c -m32 -z execstack -std=c99 -O0 -fno-stack-protector

run:
	./exploit

clean:
	rm main 2> /dev/null
	rm exploit 2> /dev/null
	rm a.out 2> /dev/null
