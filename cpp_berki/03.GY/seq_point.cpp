#include <iostream>

int i;

int f()
{
	++i;
	std::cout<<"f():"<<i;
	return i;
}

int g()
{
	--i;
	std::cout<<"g():"<<i;
	return i;
}

int main()
{
	std::cout<<f()<<g()<<std::endl;
	std::cout<<f(),std::cout<<g()<<std::endl;
	std::cout<<(f(),g(),f())<<std::endl;
}