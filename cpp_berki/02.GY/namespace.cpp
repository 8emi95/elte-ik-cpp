#include <iostream>

namespace feri
{
	int log(int n)
	{
		if(n == 0)
			return 1;
		int result = 0;
		while(n != 0)
		{
			n /= 10;
			++result;
		}
		return result;
	}
}

namespace kati
{
	int cica = 4;
	int log(int n)
	{
		if(n == 0)
			return 1;
		int k = 1;
		int result = 0;
		while(n >= k)
		{
			k *= 10;
			++result;
		}
		return result;
	}
}

int main()
{
	using namespace kati;
	using std::cout;
	cout<<cica<<std::endl;
	cout<<feri::log(1)<<std::endl;
	cout<<log(1)<<std::endl;
	cout<<log(10)<<std::endl;
	cout<<log(1000)<<std::endl;
	cout<<log(98)<<std::endl;
}