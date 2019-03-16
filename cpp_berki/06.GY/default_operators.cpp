#include <iostream>

struct Y {
	Y() { std::cout<<"Y()"<<std::endl; }
	~Y() { std::cout<<"~Y()"<<std::endl; }
};
struct Z {
	Z() { std::cout<<"Z()"<<std::endl; }
	~Z() { std::cout<<"~Z()"<<std::endl; }
};
struct X {
	Y y;
	Z z;
};
int main()
{
	X x;
	X x2 = x;
	x2 = x;
	//x2 == x;
	//x2 != x;
}