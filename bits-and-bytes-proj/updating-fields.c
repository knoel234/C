#include <stdio.h>

int main()
{
	unsigned int N = 389710625u;
 

	int mask = ( ((1 << 3) - 1) <<  24);
	int newN = N & (~mask);
	int newM = 2 << 24;
	int result = newM | newN;

	int mask2 = ( ((1 << 6) -1 ) << 14);
	int newN2 = result & (~mask2);
	int newM2 = 17 << 14;
	int result2 = newM2 | newN2;

	printf("%08x\n",result2);

}