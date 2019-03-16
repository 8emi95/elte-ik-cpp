#include <iostream>

class Point
{
  public:
    int x, y;
};

class IntOnHeap
{
    int *i;

  public:
    IntOnHeap() : i(new int(0)) { std::cout << "IntOnHeap default constructor running" << std::endl; }

    IntOnHeap(int x) : i(new int(x)) { std::cout << "IntOnHeap Constructor running" << std::endl; }

    IntOnHeap(const IntOnHeap &other) : i(new int(*other.i))
    {
        std::cout << "IntonHeap copy constructor running" << std::endl;
    }

    ~IntOnHeap()
    {
        std::cout << "IntOnHeap destructor running" << std::endl;
        delete i;
    }

    IntOnHeap &operator=(const IntOnHeap &other)
    {
        *i = *other.i;
        return *this;
    }
};

int main()
{
    //    Point a;
    //    a.x = 1;
    //    a.y = 2;
    //    Point b = a; // A fordító generál copy konstruktort
    //    Point c;
    //    c = b; // A fordító generál értékadó operátort
    //    std::cout << "a.x : " << a.x << std::endl;
    //    std::cout << "a.y : " << a.y << std::endl;
    //    std::cout << "b.x : " << b.x << std::endl;
    //    std::cout << "b.y : " << b.y << std::endl;
    //    std::cout << "c.x : " << c.x << std::endl;
    //    std::cout << "c.y : " << c.y << std::endl;

    // IntOnHeap iohA = iohB = iohC(3); // fordítási hiba! iohB not declared

    IntOnHeap iohC(3), iohA = iohC;

    IntOnHeap s;

    s = iohC;
    return 0;
}