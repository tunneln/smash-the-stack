#include <stdio.h>

// Simple program to determine if system is little or big endian
int main()
{
	int num = 1;
	if (*(char *)&num == 1)
		printf("\nLittle-Endian\n");
	else
		printf("Big-Endian\n");

	return 0;
}
