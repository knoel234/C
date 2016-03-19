#include <stdio.h>

int main()
{
	char c = 'C';
	char a = 65;
	char A = 'A';
	char F = 'F';
	char E = 'E';
	char B = 'B';
	char C = 'C';
	

	printf("c = %C\n", c);
	printf("a = %C\n", a);
	printf("%C%C%C%C%C%C%C%C\n",C,A,F,E,B,A,B,E);
	printf("number of bytes: %u.\n",(unsigned)sizeof("CAFEBABE"));
}