#include "stdio.h"
#define FAHR2CELS(x) 5./9*(x-32)
#define LOWER -140
#define UPPER 200
#define STEP 10

int main()
{
	int i;
	for( i = LOWER ;i<=UPPER;i+=STEP)
	{
		printf( "%d fahr %f celsius\n",i ,FAHR2CELS(i));
	}
	return 0;
}
