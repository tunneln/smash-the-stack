#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 256

int main(int argc, char **argv)
{
//	void *stack_address = &buf[0];
	char buf[256];
	if (argc < 2) {
		printf("%d", (int)buf);
    	exit(1);
  	}

//	printf("The head of the stack address is %p\n", stack_address);
  	strcpy(buf, argv[1]);

	return 0;
}

