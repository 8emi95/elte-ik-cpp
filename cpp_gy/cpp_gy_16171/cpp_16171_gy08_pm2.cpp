2016.11.09.
8. C++ GY

+/-: sorolj fel 3 db STL konténert (set, multiset, map)


osztályok alapvető műveletei:
-----------------------------

class X {}; // üres

sizeof(X) == sizeof(char)


void f() // érték szem.
{	//v{}
	X a; // default ctor (default konstruált objektum)
	X b = a; // copy ctor, X b(a)
	a = b; // értékadás - 2 obj (tartalom másolódik)
	X *p = &a; // címképzés(2) (2?)
} // dtor: destruktor meghívódik

// Java
X s; // = null;
s = new X();
X c = s;
// 1 obj 2 hovatkozással


default constructor:
--------------------
- paraméter nélkül meghívható

X a[5]; // X-ekből álló 5-elemű tömböt hozunk létre
// 5x def ctor
std::vector<X> v(5); // def ctor 1x
std::map<int, X> m; // mapből nem lehet kiindeyelni
m[2]; // def ctor


class Foo // nyelvi konstrukció...
{
	std::string s;		// } private
	std::vector<int> v;	// }
};

Foo a; // a.s és a.v objektumok itt létrejönnek, def ctor-hívásokkal

class vehicle
{
	std::string reg; // vehicle v; // classon kívül
public:
	vehicle (const std::string &s)
	{
		reg = s;
	}
};
vehicle v("AAA-123");
vehicle s(); // lefordul, függetlenül attól h van-e def ctorja vehiclenek, nem ctor-hívás hanem fv-deklaráció


int i = 3;
Foo X(double (i)); // fv-dekl
// C++11: szabvány, uniform initialization
// {}-ben....


- hívható: - semmilyen ctor-t nem írunk
		   - ha írunk def ctor-t


struct Foo
{
	Foo() { ... }
};
Foo x; // { ... } le fog futni


class complex
{
	double re, im;
public:
	complex(double r = 0.; double i = 0.)
	{
		re = r;
		im = i;
	}
};
complex n; // nulla



copy ctor, értékadás:
---------------------
- mindig léteznek/létrejönnek
- működés: tagonkénti másolás szemantikája

class complex
{
	double re, im;
};

complex a(1.2, 2.9);
re [1.2] } a
im [2.9] }

complex b = a;
re [1.2] } b
im [2.9] }

vector
[capacity]		[cap]
[size]			[size]
[pointer]		[]

 cap
__|__
[ ][] // p 1.re mitat, üres  is
_,_
size



class Foo
{
	// ...
public:
	// Foo(Foo rhs) { ... } // Foo rhs = s
	Foo(const Foo &rhs) { ... }
	Foo &operator=(const Foo &rhs) { ... }
};


std::auto_ptr
heap-en leallokált tárterületre hivatkozott
a -> []
b = a;
b -> [] // a már nem mutat rá, jobboldali lemásolt paraméter nullpointerre vált

x = (y = (z = w));
			z
		y
	x

clonable:
clon
Ada: limited


class limited
{
private:				// C++11: = delete =(explicit letiltja a műveleteket)
	limited(const limited&) = delete; // dekl de nem írja meg
	limited &opreator=(const limited&) = delete;
};


class X
{
public:
	// ...
	~X() {} // dtor
}

X *p = new X();
delete p;