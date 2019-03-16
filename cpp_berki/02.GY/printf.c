#include <stdio.h>

int main()
{
	int a = 30;
	printf("Decimal: %d, %3d\n", a, a);
	printf("Decimal: %d, %3d\n", 30, 300);
	a = -10;
	printf("Signed: %d, unsigned: %u\n", a, a);
	a = 31;
	printf("Hexa: %x, %x\n", a, 255);
	printf("Octal: %o, %o\n", 8, 9);
	printf("Characters: %c, %c\n", 'A', 65);
	const char* s = "Hello World!";
	printf("%s\n", s);
	return 0;
}