#include <iostream>
#include <iomanip> //std::setw
#include <math.h>  //sqrt

int main()
{
	int a = 10;
	std::cout<<"decimal: "<<a<<" "
			 <<std::setw(1)<<a<<" "
			 <<std::setw(2)<<a<<" "
			 <<std::setw(3)<<a<<" ";
	std::cout<<1<<" "
			 <<std::setw(3)<<1<<" "
			 <<std::endl;
	int b = -10;
	std::cout<<"signed: "<<b<<", unsigned: "<<static_cast<unsigned int>(b)<<std::endl;
	std::cout<<"octal: "<<std::oct<<a<<std::endl;
	std::cout<<"hexadecimal: "<<std::hex<<a<<" "<<128<<" "<<255<<std::dec<<std::endl;
	std::cout<<"character: "<<'\x82'<<' '<<'é'<<' '<<'a'<<std::dec<<std::endl;
	std::string alma = "alma";
	std::cout<<"string: "<<alma<<std::endl;
	float pi = 3.14;
	float c = sqrt(2);
	std::cout<<"float: "<<pi<<" "
			 <<std::setprecision(1)<<pi<<" "
			 <<std::setprecision(2)<<pi<<" "
			 <<std::setprecision(4)<<pi
			 <<c<<" "
			 <<std::setprecision(1)<<c<<" "
			 <<std::setprecision(2)<<c<<" "
			 <<std::setprecision(12)<<c<<" "
			 <<sqrt(5)<<" ";
	std::cout<<sqrt(5)<<std::endl;
	return 0;
}