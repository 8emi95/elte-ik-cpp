#include <iostream>

typedef bool(*comparator)(int,int);

bool lesser(int i, int j)
{
	return i>j;
}

bool greater(int i, int j)
{
	return i<j;
}


void sort(int* numbers, int size, comparator comp = lesser)
{
	for(int i = size - 1; i>0; --i)
	{
		for(int j = 0; j < i; ++j)
		{
			if (comp(numbers[j], numbers[j+1]))
			{
				int temp = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = temp;
			}
		}
	}
}

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
	int j[] = {3, 2 , 5 , 4};
	print_array(j, sizeof(j)/sizeof(j[0]));
	sort(j, sizeof(j)/sizeof(j[0]), greater);
	print_array(j, sizeof(j)/sizeof(j[0]));
	sort(j, sizeof(j)/sizeof(j[0]));
	print_array(j, sizeof(j)/sizeof(j[0]));
}