#include <iostream>

void print_array(int* j, size_t size)
{
	for(size_t i = 0; i < size;++i)
	{
		std::cout<<j[i];
	}
	std::cout<<std::endl;
}


int main()
{
	int j[];
	print_array(j, sizeof(j)/sizeof(j[0]));
	j[1] = 4;
	print_array(j, sizeof(j)/sizeof(j[0]));
}