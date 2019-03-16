#include <iostream>

void print(std::string s)
{
	std::cout<<s<<std::endl;
}

void print(int& i)
{
	std::cout<<i<<std::endl;
}

void print(const int& i)
{
	std::cout<<"Const:"<<i<<std::endl;
}

int main()
{
	int i = 5;
	std::string s = "alma";
	print(i);
	print(5);
	print(s);
}