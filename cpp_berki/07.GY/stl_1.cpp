#include <iostream>

int main()
{
	int *a = new int[1];
	size_t size = 1;
	size_t pos = 0;
	int i;
	while(std::cin>>i)
	{
		if(pos == size)
		{
			int *b = new int[size * 2];
			for(int j = 0; j < size; ++j)
			{
				b[j] = a[j];
			}
			size *= 2;
			delete[] a;
			a = b;
		}
		a[pos] = i;
		++pos;
	}
	std::cout<<a[0];
	for(int j = 1; j < pos; ++j)
		std::cout << " " << a[j];
	std::cout<<std::endl;
	i = pos - 1;
	while(i >= 1)
	{
		int j = 0;
		while(j <= i - 1)
		{
			if(a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			++j;
		}
		--i;
	}
	std::cout<<a[0];
	for(int j = 1; j < pos; ++j)
		std::cout << " " << a[j];
	std::cout<<std::endl;
	delete[] a;
}