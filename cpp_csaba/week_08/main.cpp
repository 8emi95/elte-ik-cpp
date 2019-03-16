#include <iostream>

void f(int a)
{
    std::cout << "int param" << std::endl;
}

void f(int &a)
{
    std::cout << "int ref param" << std::endl;
}

void f(int *a)
{
    std::cout << "int ptr param" << std::endl;
}

template <int N>
void f(int (&a)[N])
{
    std::cout << "templ, arr ptr param, size:" << N << std::endl;
}

int main()
{
    int i[] = {23, 11, 0};
    f(i);  // void f(int *a) !!!

}