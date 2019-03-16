#include <iostream>

template <class T, int N>
int size(const T(&a) [N])
{
	return N;
}

int main()
{
	int a[3];
	char b[5];
	std::cout<<size(a)<<std::endl;
	std::cout<<size(b)<<std::endl;
}