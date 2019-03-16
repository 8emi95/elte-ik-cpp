#include <iostream>

double fahr2cels(double fahr)
{
	return 5./9*(fahr - 32);
}

int main(int, char**)
{
	const int lower = -140;
	const int upper = 200;
	const int step = 10;
	for(int i = lower;i<=upper;i+=step)
	{
		std::cout<<i<<" fahr "<<fahr2cels(i)<<" celsius"<<std::endl;
	}
	return 0;
}