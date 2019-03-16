#include "stdio.h"

int main()
{
	int i;
	for( i = -140 ; i<=200 ; i += 10)
	{
		printf( "%d fahr %d celsius\n",i ,5/9*(i-32));
	}
	return 0;
}