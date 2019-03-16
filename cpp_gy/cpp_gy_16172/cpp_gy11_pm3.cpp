2017.05.10.
11. C++ GY

+/-: sorolj fel 3 STL konténert

-------------------------------------
Öröklődés:
-------------------------------------
- kódújrafelhasználás:

std::vector<int> v(3); // OIL. (?)
std::string p(3); // ford. hiba
std::string q(c); // fut. hiba
std::string msg("Hello");

class safe_string
{
    std::string s;
public:
    safe_string(const char *p) : s(p ? p : "") {}
    int length() const
    {
        return s.length();
    }
    void push_back(char ch)
    {
        s.push_back(ch);
    }
};

class safe_string: public std::string
{
public:
    safe_string(cinst char *p) : std::string(p ? p : "") {}
};

safe_string s(0);
s.push_back('a');
std::cout << s.length();


- polimorfizmus/többalakúság:

class Base
{
public:
    virtual void f()
    {
        std::cout << "Base::f()";
    }
    virtual ~Base() {}
};

class Der: public Base
{
public:
    virtual void f()
    {
        std::cout << "Der::f()";
    }
    virtual ~Der() {}
};

Base *p = 0;
p = new Base();
p -> f(); // Base::f()
delete p;
p = new Der();
p -> f(); // Der::f()
delete p;

void g(Base *p) // * -> & ???
{
    p -> f();
} // lefordítható: függként???          esetszétválasztás


Base b;
b.f(); // Base::f()
Der d; // statikus típusinformáció
d.f(); // Der::f()


// ............

class Shape
{
    int color;
public:
    Shape(int c) : color(c) {}
    virtual double get_area() const = 0; // =0 pure virtual -> absztrakt osztály
    int get_color() const
    {
        return color;
    }
    virtual ~Shape() {}
}

Shape *p = 0;
p = new Circle(3, 2.4);
delete p; // élettartam vége


void g(Base *p) // * -> & ???
{
    p -> f();
}
void h(Base b)
{   // ˇcsak a Base részt másolja
    b.f(); // Base::..............
}


void print(Shape *s)
{                    //ˇclass Shape
    std::cout << s -> get_color() << ' ' << s -> get_area(); // altípushelyes
} // lefordul


template<class Sh>
void print(const Sh &s)
{
    std::cout <<s.get_color() << ' ' << s.get_color();
} // nem fordul le


class Circle: public Shape
{
    double rad;
public:
    Circle(int c, double r) : Shape(c), rad(r) {}
    virtual double get_color() const
    {
        return rad * rad * 3.14;
    }
    cirtual ~Circle() {}
};


// nah