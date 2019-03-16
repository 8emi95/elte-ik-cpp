#include "stdio.h"

int main()
{
	int lower = -140;
	int upper = 200;
	int step = 10;
	int i;
	for( i = lower ; i<=upper ; i += step)
	{
		printf( "%d fahr %d celsius\n",i ,5/9*(i-32));
	}
	return 0;
}