#include <stdio.h>
#include <stdlib.h>

void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
