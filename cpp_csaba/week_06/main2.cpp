#include <iostream>

namespace ns
{
int a;
}

class test
{
  private:
    int attribute;

  public:
    test()
    {
        std::cout << "default constructor" << std::endl;
    }
    test(const test &other) : attribute(other.attribute)
    {
        std::cout << "copy constructor" << std::endl;
    }
    ~test()
    {
        std::cout << "destructor" << std::endl;
    }

    void printAttribute()
    {
        std::cout << attribute << std::endl;
    }
};

void f(test x){
    
}

void fr(test& x){

}

void fcr(const test& x){

}

int main()
{
    test a;
    test b(a);
    test c = a;
    test d;
    d = a;

    std::cout << std::endl;
    test e[2];

    std::cout << std::endl;
    f(a);
    fr(a);
    // fcr(*(new test); //memory leak

    std::cout << ns::a << std::endl;
}