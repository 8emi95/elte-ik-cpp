#include <iostream>

template <class T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void print(const T& a, const T& b)
{
	std::cout<<a<<" and "<<b<<std::endl;
}

template <>
void print(const std::string& a, const std::string& b)
{
	std::cout<<a<<' '<<b<<std::endl;
}

template <typename t>
const t& max(const t& a, const t& b){
	return a<b?b:a;
}

int main()
{
	int a = 5, b = 3;
	swap(a,b);
	print(a,b);
	std::string c = "Hello", d = "World!";
	swap(c,d);
	print(c,d);
	std::cout<<max(1,2)<<std::endl;
	std::cout<<max<char>('s','a')<<std::endl;
	std::cout<<max<double>(1, 2.6)<<std::endl;
}