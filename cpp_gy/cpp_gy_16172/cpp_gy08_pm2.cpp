2017.04.19.
8. CPP GY

+/-:
void f(int a, int &b, int *c)
{
    int s = a + b + (*c); // 6
    a = b = (*c) = s; // 6 mind
}
int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    f(x, y, &z);
    // x nem változik, csak lemásoltuk, 1 marad
    // y és z 6 és 6 lesz
}

lefordul? igen
ha nem, miért? -
ha igen, mi történi ka faraméterekkel? ^up


---------------------------------------------------------
Objektum-oruentált programozás:
---------------------------------------------------------

class X {};
void f()
{   // sizeof(X) == sizeof(char)
    X a; // valid létrehozott, működőképes, default ctor objektum
    X b = a; // copy ctor hívás, X b(a), 2 kül obj
    a = b; // értékadás
    X *p = &a; // címképzés, 2 db
}


Java:
-----
X s; // nullhivatkozás
s.f(); // NullPointerException
s = new X(); // már létezik
X t = s; // 1 obj, 2 hivatkozás


default ctor
------------
- pm nélkül hívható
X s[5];
std::vector<X> v(5); // 1x def ctor
std::map<X> m; // 1x def ctor
m[4]; // 1x def ctor

// ....

mikor hívható?
- ha írunk egy def ctor-t
- ha semmilyen ctor-t nem írunk

class Widget
{
    std::vector<int> v;
};
Widget w; // w.v léteznie kell

class Table // nem def ctor-álható
{ // kis- nagybetű számít
public:
    Table(int i) {...}
};
Table(3); // kell szám

class X {};
X s(); // nem ctor hívás
X b{}; // def ctor hívás C++11-ben

C++11: uniform initialization {ctor.params} -> ctor hívás


class complex
{
    double re, im; // private
public:
    complex(double r = 0.0, double i = 0.0)
    {
        re = r;
        im = i;
    }
};
complex a(1.5, 2.3);
complex b(3.7); // 3.7 + 0.0i
complex n; // komplex nulla
complex s(0.0, 3.4);


copy ctor / értékadás
---------------------
mindig léteznek, tagonként másolnak: copy ctor adattagokat copy ctor-ral másolja, értékadás adattagokat értékadással

complex c = a;
/*
a       c
[1.5]   [1.5]
[2.3]   [2.3]
*/


Vector

[capacity]
[size    ]
->
[....] []
˘size˘
˘capacity˘

Vector a;
Vector rhs = a; // nah
Vector &rhs = a; // nah, meg lehet változtatni a lemásolandó adatot
// & kötelező, const kell
Vector b = a;
a = b; // a.operator=(b)

class Vector
{
    int cap, size;
    T *ptr;
public:
    Vector(const Vector &rhs) {...}
    Vector &operator=(const Vector &rhs) {...}
}

C++ smart pointer: garantáltan fel legyen szabadítva az allokált tárterület
auto_ptr

void f()
{
    X a;
    X b = a;
} // dtor, auto lefut élettartam végén, nincs paramétere

class Foo
{
public:
    ~Foo() {}
;}