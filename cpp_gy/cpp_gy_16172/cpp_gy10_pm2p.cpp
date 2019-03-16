2017.05.03.
10. C++ GY

pót +/-:
class X
{
    public:
    X(int i = 3) {}
}
void f()
{
    // X-eket kell létrehozni a stack-en kül paraméterezéssel
}

---------------------------------------------------------
Típussal paraméterezés:
---------------------------------------------------------
/* C-ben em létezett, de */
int printf(char *str, ...);
void* malloc(int bytes);
void free(void *ptr);
#define MAX(a,b) ((a) < (b) ? (b) : (a))

// C++
template<class T>
class T& max(const T &a, const T &b)
{
    return a < b ? b : a;
} // -> ebből nem lehet alacsony szintű kódot létrehozni

std::cout << max(5, 7); // T ekviv int, pm-dedukció
std::cout << max(8.3, 3.4); // T ekviv double
std::cout << max(8, 3.7); // ford hiba
std::cout << max<double>(7, 4.3); // lefordul
std::cout << max("kukumuku", "blabla"); // ford hiba, const char[9] const char[7]
std::cout << max("kuku", "muku"); // lefordul
std::cout << max<std::string>("kukumuku", "xy"); // xy

class complex
{
    double re, im;
    public:
    // ...
}; // nincs operator<

complex a(3.7, 4.1);
complex b(1.8, 6.7);
complex c = max(a, b); // ford hiba, T ekviv complex
std::list<int> s;
std::sort(s.begin(), s.end()); // RandomAccessIterator-t ár

            // InputIterator
template<class Iter, class Fun>
Fun for_each(Iter first, Iter last, Fun f)
{
    while (first != last)
    {
        f(*first++); // f.operator()(*first++);
    }
    return f;
}

void print(int i)
{
    std::cout << i << ' ';
}
std::for_each(v.begin(), .end(), print)

Iter:
- operator!=
- operator++ (int)
- operator*
(- copy ctor)
pl. pointer, STL-es konténerek iterátora?

Fun:
(- copy ctor)
- függvényhívás

class Print
{
    std::ostream &os;
    public:
    Print(std::ostream &o) : os(o) {}
    void operator()(int i)
    {
        os << i << ' ';
    }
};

Print p(std::cerr);
p(3);
p(2);

std::for_each(v.begin(), v.end(), Print(std::cout));


template<class T> // típusbiztos
class Print
{
    std::ostream &os;
    public:
    Print(std::ostream &o) : os(o) {}
    void operator()(const T &t)
    {
        os << t << ' ';
    }
};

Print<double> p(std::cerr);
p(1.19);
p(2.13);
p("blabla"); // ford hib
Print<std::string> q(std::cout);
q("blabla");
q(1.47); // ford hiba


class Print // típusbiztos
{
    std::ostream &os;
    public:
    Print(std::ostream &o) : os(o) {}
    template<class T>
    void operator()(const T &t)
    {
        os << t << ' ';
    }
};

Print pr(std::cout);
pr(3);
pr(1.4);
pr("abc");
int s;
std::cin >> s,
pr(s);