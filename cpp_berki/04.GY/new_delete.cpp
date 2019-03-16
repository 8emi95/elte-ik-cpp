#include <iostream>

void print_array(int* j, size_t size)
{
	for(size_t i = 0; i < size;++i)
	{
		std::cout<<j[i];
	}
	std::cout<<std::endl;
}

int* factory()
{
	int* result = new int[5];
	return result;
}

int main()
{
	int* i = factory();
	print_array(i, 5);
	delete[] i;
}