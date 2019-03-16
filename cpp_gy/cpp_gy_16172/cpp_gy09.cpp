2017.04.26.
9. CPP GY

void f()
{       // sizeof(date) == ?
    date d(2017, 3, 19);
    d.set_day(13);
    // PIMPL idiom, opaque pointer, compilation firewall
}

// Java:
Date d = new Date(2017, 3, 19);
d.set_day(13);
Date n = null;
n.set_day(5); // NPE


date_impl.h:
------------
class date_impl
{
public:
    date_impl(int y, int m, int d);
    void set_day(int d);
};


date.h:
-------
class date_impl;
class date
{
    date_impl *p;
public:
    // date(int y, int m, int d);
    // void set_day(int d);
    date(const date &rhs);
    date &operator=(const date &d);
    ~date();
};


date_impl.cpp: ???
--------------
#include "date_impl.h"
date_impl::date_impl(int y, int m, int d) {...}
void date_impl::set_day(int d) {...}


date.cpp:
---------
#include "date.h"
#include "date_impl.h"
date::date(int y, int m, int d)
{
    // p = new date_impl(y, m, d); // előző konsi meghívása
    *p = *(d.p);
    return *this;
}
/*void date::set_day(int d)
{
    p -> set_day(d);
}*/
/*date::date()
{
    p = new date_impl(*(rhs.p)); // date_impl copy ctor
}*/
date::~date() { delete p; }



void f()
{
    date s(2017, 4, 10);
    s.set_day(15);
    date d = s; // copy ctor
/*
s -> [] date_impl
     ^d is errre fog mutatni
*/
// kikommentezés + új konsik után már nem ugyanoda mutat
    s = d; // értékadás
    s.operator = (d);
}


void fv()
{
    date a(...);
    if (a.get_day() == 5)
    {
        date b = a;
    } // dtor
} // dtor
// nem szivárog a memória


class Vector
{
    int cap, s; // elemszám
    T *ptr;
public:
    Vector(int i) : cap(i), s(o) // cap(i), s(o) ->inicializáló lista
    {
        ptr = new T[cap];
    }
    ~Vector()
    {
        delete []ptr;
    }
    Vector(const Vector &rhs)
    {
        cap = rhs.cap;
        s = rhs.s;
        ptr = new T[cap];
        for (int i = 0; i < rhs.s; ++i)
        {
            ptr[i] = rhs.ptr[i];
        }
    }

    Vector &operator=(const Vector &rhs)
    {
        if (this != &rhs) // 1
        {
            delete []ptr; // 2
            cap = rhs.cap;
            s = rhs.s;
            ptr = new T[cap];
            for (int i = 0; i < rhs.s; ++i)
            {
                ptr[i] = rhs.ptr[i];
            }
        }
        return *this;
    }
};

Vector v(8);
Vector s = v;
v = s;



class cube
{
    const int size;
public:
    cube(int s) : size(s) // const size inicializálása, ezen a ponton jönnek létre az adattagok
    {
        // size = s; // fordítási hiba (nem változhat meg const size értéke)
    }
}


class Foo
{
    int s, i;
    public:
    Foo(int x) : i(x++), s(x) {...}
}

Foo f(3);
f.s == 3;
f.i == 3;