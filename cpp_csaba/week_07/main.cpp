#include <iostream>
#include <deque>

class test
{
  private:
    static int counter;
    int attribute;

  public:
    test() : attribute(counter++)
    {
        std::cout << "default constructor of Obj No.: " << attribute << std::endl;
    }
    test(const test &other) : attribute(counter++)
    {
        std::cout << "copy constructor of Obj No.: " << attribute << std::endl;
    }
    ~test()
    {
        std::cout << "destructor of obj No.: " << attribute << std::endl;
        --counter;
    }

    void printAttribute()
    {
        std::cout << attribute << std::endl;
    }

    const int &getAttribute() const
    {
        std::cout << "attribute address of obj No.: " << &attribute << std::endl;
        return attribute;
    }
};
int test::counter = 0;

test f()
{
    test a;
    return a;
}

int a = 1;
void f(int &x, int &y) //nem const int &!!!
{
    int t = x;
    x = y;
    y = t;
}

typedef test kukumuku; //lehet szátmaztatni typedefből WTF

class asd : public kukumuku
{
};

// template<class T> //nope
// enum ABC{
//     A,B,C
// };

template <class T> //yepp
struct ABC
{
    int c;
};

template <class T>
const T &max(const T &a, const T &b)
{
    return a > b ? a : b;
}

int main()
{
    // test i[5];
    // i[4].~test(); // destruktor explicit hívása

    // const test ct;
    // const int &x = ct.getAttribute();
    // std::cout << "address of const int& x: " << &x << std::endl;
    // std::cout << std::endl;

    // test *t = new test[5];
    // delete [] t;

    test k = f();
    // f(a,2);
    std::cout << "kaksi" << std::endl;

    std::deque<test> deque;
    deque.push_back(k);
    deque.erase(deque.begin());
    std::cout << "kaksi" << std::endl;
    std::cout << max("abc", "sef") << std::endl;
}