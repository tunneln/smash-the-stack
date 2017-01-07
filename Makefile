all:
	gcc -w -o exploit exploit.c -m32 -z execstack -std=c99 -O0 -fno-stack-protector
	gcc -w -o main main.c -m32 -z execstack -std=c99 -O0 -fno-stack-protector

run:
	./exploit

clean:
	rm main
	rm exploit
