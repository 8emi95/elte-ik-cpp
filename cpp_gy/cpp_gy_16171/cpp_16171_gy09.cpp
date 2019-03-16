2016.11.16.
9. C++ GY

Java: referenciaszemantika
~~~~~~~~~~~~~~~~~~~~~~~~~~
X a; // = null;
a = new X(...);
X b = a;
// 1 obj, 2 hivatkozás
a.f();


C++: értékszemantika
~~~~~~~~~~~~~~~~~~~~
void f()
{
	X a; // valid, működő objektum -> sizeof(x) ismert kell h legyen
	a.f(); // meg lehet hívni rajta a tagfüggvényét
	X b = a; // másik valid ob
}

*****

#include "date.h"
void g()
{
	date d(2016, 11, 16);
	std::cout << d.get_year();
	date s = d; // tagonkénti másolás
	/*			date_impl
		d ->    [....]
		s ->
	*/
	// copy ctor
	// d = s; // értékadás, d.operator=(s)
	/*			date_impl
		d ->	[....]
		s ->	[....]
	*/
}

void f()
{
	date a(2015, 12, 31);
	//...
	if(a.get_year() < 2016)
	{
		int s = a.get_year();
		date b = a;
		// -> b destruktor
		a.set_year(2016);
	} // -> a destruktor
}


date.h:
-------
class date_impl;
class date
{
	date_impl *p;
public:
	date(int y, int m, int d);
	//int get_year() const;
	date(const date& rhs);
	~date(); // dtor, nem mi hívogatjuk hanem automatikusan lefur
};


date_impl.h:
------------
class date_impl
{
	//...
public:
	date_impl(int y, int m, int d);
	int get_year() const; // get_year meghívható egy konstans dátumon mert nem változtatja meg az állapotát a dátumnak (?)
	//...					 meghívható const és nem const obj-on is
};


date_impl.cpp:
--------------
//...


date.cpp:
---------
#include "date_impl"
date::date(int y, int m, int d)
{
	p = new date_impl(y, m, d);
}
/*int date::get_year() const
{
	return p -> get_year();
}*/
date::date(const date& rhs)
{
	p = new date_impl(*(rhs.p));
	//  ˇdate_impl copy ctor
}
//... const referencia????
date& date::operator=(const date& rhs)
{
	*p = *(rhs.p);
	return *this; // ezen az obj-on hívtuk meg
}
date::~date()
{
	delete p;
}


-------
date_imp x(2016, 8, 2);
x.get_year(); // &x adódik át this néven


pimpl-idiom / opaque pointer



*************************

vector
T: vmilyen típus
[cap]
[s  ]
[   ] -> [...]

class Vector
{
	int ap, s;
	T *p;
public:			// inicializáló lista
	Vector(int i):cap(i), s(0) // i kezdőkapacitás
	{
		p = new T[cap];
	}
	~Vector()
	{
		delete []p;
	}
	Vector(const Vector& rhs) // copy ctor
	{
		cap = rhs.cap;
		s = rhs.s;
		p = new T[cap];
		for (int i = 0; i < s; ++i)
		{
			p[i] = rhs.p[i];
		}
	}
	Vector& operator=(const Vector& rhs)
	{
		if (this != &rhs) // címképző operátor
		{
			delete[] p;
			cap = rhs.cap;
			s = rhs.s;
			p = new T[cap];
			for (int i = 0; i < s; ++i)
			{
				p[i] = rhs.p[i];
			}
		}
		return *this;
	}
	int size() cosnt
	{
		//...
	}
};


class X
{
	Foo f;
public:
	X(int i):f(i) {}
};
X a;

class Foo
{
	//...
public:
	Foo(int i);
	//...
}


const int n; // ford hiba
n = 5; // ford hiba

class Table
{
	const int n; // kötelező
public:
	Table(int i):n(i) {}
};


class Point
{
	int x, y; // ebben a sorrrendben jönnek létre az adattagok
public:
	Point(int s):y(s), x(y) {}
				// felcseréli a sorrendet úgy ahogy szerepeltek
};

Point p(5);
p.x értéke nem definiált
p.y értéke 5


Vector a(8);
Vector b = a; // ugyanoda mutatnak


Vector(4);
Vector s = v;
v = s;
Vector
[4]			-> [4]
[0]			-> [0]
[ ]			-> [ ]
-> [   ]		-> [   ]



Vector v(6);
//...
const Vector c = v;
std::cout << c.size();
std::cout << v.cize();