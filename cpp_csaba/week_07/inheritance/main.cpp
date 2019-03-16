#include <iostream>
#include <typeinfo>

class parent
{
  public:
    const char *name;

    parent() : privInt(privStatInt++), name("parent")
    {
        std::cout << "default constructor of parent No.: " << privInt << std::endl;
    }
    parent(const parent &other) : privInt(privStatInt++), name("parent")
    {
        std::cout << "copy constructor of parent No.: " << privInt << std::endl;
    }
    ~parent()
    {
        std::cout << "destructor of parent No.: " << privInt << std::endl;
        --privStatInt;
    }

    static void printPrivStatInt()
    {
        std::cout << privStatInt << std::endl;
    }

    void printPrivInt()
    {
        std::cout << "privInt address of parent No.: " << &privInt << std::endl;
        std::cout << privInt << std::endl;
    }

    const int &getPrivInt() const
    {
        return privInt;
    }

    virtual void getSpecial()
    {
        std::cout << "special of parent No.: " << privInt << std::endl;
    }

    void operator+(parent &other)
    {
        std::cout << "parent operator method of parent No.:" << privInt << std::endl;
    }

  protected:
    int privInt;
    static int privStatInt;
    void protectedFnc() const
    {
        std::cout << "protected function of parent No.: " << privInt << std::endl;
    }
};
int parent::privStatInt = 0;

class child : public parent
{
  public:
    const char *name;

    child() : parent(), privInt(privStatInt++), name("child")
    {
        std::cout << "default constructor of child No.: " << privInt << std::endl;
    };
    child(const child &c) : parent(c), privInt(privStatInt++), name("child")
    {
        std::cout << "copy constructor of child No.: " << privInt << std::endl;
    };
    ~child()
    {
        std::cout << "destructor of child No.: " << privInt << std::endl;
        // --privStatInt;
    }
    void getSpecial()
    {
        std::cout << "special of child No.: " << privInt << std::endl;
    }

    void f()
    {
        std::cout << typeid(this).name() << std::endl;
    }

  protected:
    int privInt;
    static int privStatInt;
};
int child::privStatInt = 0;

// void operator+(parent &a, parent &b)
// {
//     std::cout << "external operator method " << std::endl;
// }

/* */

// struct Foo
// {
//     int a;
//     void f()
//     {
//         // Foo g;
//         // g.a = 3;
//         // this = &g;
//     }
// };

struct S
{
    static int x;
};
int S::x = 0;

template <typename T>
T max(const T &a, const T &b);

struct Foo
{
    int a;

    Foo(int i) : Foo(i, 0)
    {
    }

    Foo(int i, int j) : a(i)
    {
    }
};

/** */

template <int a>
class Test
{
  public:
    Test() {}
    int MyMethod1() { return a; }
};

template <int b>
class Another : public Test<b>
{
  public:
    Another() {}
    void MyMethod2()
    {
        Test<b>::MyMethod1();
    }
};

int main()
{
    // parent *p;
    // child child1, child2 = child1;
    // std::cout << "/* child1.getPrivInt */" << std::endl;
    // child1.getPrivInt();
    // std::cout << "/* child1.getSpecial */" << std::endl;
    // child1.getSpecial();
    // std::cout << "/* child1.f */" << std::endl;
    // child1.f();

    // std::cout << std::endl;
    // p = &child1;
    // std::cout << "/* Parent ptr on child p->getSpecial() */" << std::endl;
    // p->getSpecial();
    // std::cout << "/* child1.name */" << std::endl;
    // std::cout << child1.name << std::endl;
    // std::cout << "/* Parent ptr on child p->name */" << std::endl;
    // std::cout << p->name << std::endl;

    // int i = 2;
    // ++++i;
    // std::cout << "/* ++++i */" << std::endl;
    // std::cout << i << std::endl;

    /* elm gyak */
    std::cout << "/* elm gyak */" << std::endl;
    // Foo f;
    // f.a = 5;
    // f.f();
    // std::cout << f.a << std::endl;

    // char ch = 255;
    // int z = ch;
    // std::cout << i << std::endl;

    // struct Foo
    // {
    //     template <bool f>
    //     void bar() const {}
    // };
    // Foo f;
    // f.bar<true>();

    S s;

    // max(4.3, 23);

    /*
    template <class T, const char *p>
    class X
    {
    };
    X<int, "Studebaker"> x1; // error: string literal as template-argument
    */

    Foo foo(4);
    std::cout << foo.a << std::endl;

    parent a, b;
    std::cout << "/* a is No.: */" << a.getPrivInt() << std::endl;
    std::cout << "/* b is No.: */" << b.getPrivInt() << std::endl;
    a + b;

    // #define true false
    std::cout << true << std::endl;

    Another<5> no;
    no.MyMethod1();
    no.MyMethod2();
}