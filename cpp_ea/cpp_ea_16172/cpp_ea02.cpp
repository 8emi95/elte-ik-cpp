2017.02.22.
2. CPP EA

Preprocesszálás

1. preprocesszálási fázis: szöveges átalakítás
2. nyelvi fordítás
3. öszeszerkesztés


(header -> a'.cpp, b'.cpp, b.obj?)
a.cpp		b.cpp 		header -> nem fordítási egység
  v 		  v
a'.cpp 		b'.cpp
  v 		  v
a.obj		b.obj
  v 		  v
futtatható állomány
statikus linkelés


dinamikus linkelés:
dll/so


# peprocesszálási direktíva

direktívák:
#include <iostream> // file bemásolása
<> szabványkönyvtár része
#include "x.h" // relatív útvonalat ír le, aktuális könyvtárban keresi x.h-t (vagy x.hpp)

a.cpp:
int f(int i) {...}

a.h:
int f(int);

b.cpp:
// f("blabla"); // fordítási hiba, nem így kell meghívni (2 pm-nél is)
#include "a.h" // ide is bekerül

c.cpp:
#include "a.h" // meg ide is bekerül


complex.h:
class complex
{
	double re, im;
public:
	void set_re(double d);
};


#include "complex.h"
void complex::set_re(double d) {...} // -> complex.o

root.h:
#include "complex.h"
complex root(complex a, complex b, complex c);

root.cpp:
#include "root.h"
complex root(complex a, complex b, complex c) {...}



complex.h:
#ifndef COMPLEX__H // include guard technika
#define COMPLEX__H
class complex
{
	double re, im;
public:
	void set_re(double d);
};
#endif


main.cpp:
#include "complex.h"	// } 2x complex.h
#include "root.h"		// }
int main() {...}


C++ban: tömbök mérete fordítási időben ismert kell h legyen
C-ben:
#define N 20 // search and replace
#define M 25
int a[N];
int b[N];
int c[M];


#define SQ(x) (x * x) // makró
std::cout << SQ(5); // 5*5 -> 25
std::cout << SQ(1 + 4); // 1+4*1+4 -> 9

#define SQ(x) ((x) * (x))

int i = 3;
std::cout <<SQ(i); // ((i) * (i)) -> 9
// i = 3
std::cout <<SQ(i++); // ((i++) * (i++)) -> 12 (3*4)
// i = 5


#undef // preprocesszor szimbólum megszüntetése

#ifndef // feltételes fordítás (win linux commandline törlés más)
#ifdef // előre definiált preprocesszor szimbólumok
#if // pl. OS, C/C++ szabvány, C v. C++
#else
#elif

#define SQ(x) ((x) * (x))
NULL: makró

