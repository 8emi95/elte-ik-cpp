#include <iostream>

bool f();
bool g();
bool h();

int main()
{
    unsigned int a = 6;
    int b = -5;
    std::cout << "unsigned 6 > int 5 : " << (b < a ? "true" : "false") << std::endl;

    std::cout << std::endl;
    if (f() == g() == h()) //nem garantált kiértékelési sorrend
    {
        std::cout << "true" << std::endl;
    }

    std::cout << std::endl;
    int v[5];
    for (int i = 0; i < 5;)
    {
        v[i] = ++i; //nem garantált kiértékelési sorrend
    }

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "v[" << i << "] = " << v[i] << std::endl;
    }
}

bool f()
{
    std::cout << "function f" << std::endl;
    return false;
}
bool g()
{
    std::cout << "function g" << std::endl;
    return true;
}
bool h()
{
    std::cout << "function h" << std::endl;
    return false;
}