#include <stdio.h>
#include <stdlib.h>

#include "swap.h"

int main(int argc, char *argv[])
{
	int a = 10;
	int b = 20;

	swap(&a, &b);
	printf("a=[%d] b=[%d]\r\n", a, b);

	return 0;
}
