#include <iostream>
#include "template_class.h"


int main()
{
	Store<int> s(1);
	s.print();
	s.uppercase();
	Store<std::string> s2("c++");
	s2.print();
	s2.uppercase();
	s2.print();
}