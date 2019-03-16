#include <iostream>

void intPrinter(const int &a)
{
    std::cout << a << std::endl;
}

void f(int i = 2)
{
    std::cout << "intes f" << std::endl;
}

void f(float i = 2)
{
    std::cout << "floates f" << std::endl;
}

int main()
{
    // f(); //ambigious
    intPrinter(2e3L);
    int g(); //declaration in anywhere! wtf
    int (*a) () = g; //function pointer
    // a=g;
    std::cout << a();  
}

int g()
{
    return 2;
}