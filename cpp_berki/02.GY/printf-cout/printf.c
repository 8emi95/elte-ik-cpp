#include "stdio.h"

int main()
{
	int a = 10;
	printf("decimal: %d %1d %2d %3d\n",a,a,a,a,a);
	int b = -10;
	printf("signed:  %d, unsigned: %u\n",b,b);
	printf("octal: %o\n",a);
	printf("hexadecimal: %x %x %x\n",a,128,255);
	printf("character: %c %c %c\n",130,'é','a');
	char* alma = "alma";
	printf("string: %s\n",alma);
	return 0;
}