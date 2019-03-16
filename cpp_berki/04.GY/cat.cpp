#include <iostream>
#include <iomanip>

int main()	
{
	std::cin>>std::noskipws;
	for(char ch; std::cin>>ch; )
	{
		std::cout<<ch;
	}
}