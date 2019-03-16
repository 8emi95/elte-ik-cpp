#include <iostream>

struct A { 
 int i; 
};
struct B { 
 ~B(); 
 int i; 
};
struct C { 
C() : i() {}; 
~C(); 
int i; };

int main()
{
	std::cout<<(new A)->i<<std::endl;    //nem definiált érték
	std::cout<<(new A())->i<<std::endl; //érték szerinti inicializálás -> 0-val való feltöltés
	std::cout<<(new B)->i<<std::endl;    //alapértelmezett inicializálás -> nem definiált érték
	std::cout<<(new B())->i<<std::endl; // érték szerinti inicializálás -> fordító által generált default constructor -> 0-val való feltöltés 
	std::cout<<(new C)->i<<std::endl;    // alapértelmezett inicializálás -> default constructor
	std::cout<<(new C())->i<<std::endl; // érték szerinti inicializálás -> default constructor
}