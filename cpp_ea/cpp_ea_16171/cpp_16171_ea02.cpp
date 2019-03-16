2016.09.19.
2. C++ EA

------------------------
C++ fordítás:
------------------------
1. preprocesszálás: nem fordít (nem "előfordítás"), előfeldolgozás, szövegátalakítás, mit milyen szöveg, nyelvtől független, nem ismeri nyelv szabályait
2. nyelvi fordítás
3. összeszerkesztés: linker


1. szövegátalakítás
-------------------
preprocesszor direktíva: #-gel kezdődik -> ezekkel történik szövegátalakítás
szabályokat írunk le h miket alakítson át
- file tartalmának beillesztése

#include <iostream> // iostream fejállományt megkeresi, erre a pontra másolja a tartalmát
					// szabványkönyvtárban keres, ha <> adjuk meg
					// compiler új verziójánál át kéne írni
#include "complex.h" // több fordítási egység, külön fordulnak (ábra)
		  n.h			.cpp-t compiler lefordítja
a.cpp ... n.cpp 		.h nem tartozik a fordítás menetébe, preprocesszor bemásolja
a.obj	  n.obj

n.cpp: // van benne egy fv
void f(int i) {}

n.h:
void f(int); // ?

a.cpp:
#include "n.h"
//void f(int i) // n.cpp-t enélkül nem ismeri
			  // el lehet kerülni kézzel beírást (sok fájlnál macerás)
			  // lehet h később több paraméter kell
			  // HELYETTE FELÜLRE #include "n.h"
f("kukumuku"); // hibát ad, int kell

preprocesszort csak akk használjuk, ha érdemben hasznos (pl: fenti példa)


komplex számok
~~~~~~~~~~~~~~

complex.h:
#ifndef COMPLEX_H // preproc... nagybetű
#define COMPLEX_H
class complex // osztálydefiníció
{			 // egyszer szabad definiálni
private:
	double re, im;
public: // műveletek
	double abs();
}; // ; ???
#endif
// include guard: #ifndef #define #endif

complex.cpp: // HF

root.h:
#include "complex.h"
complex root(complex a, complex b, complex c); // fv, 3 komplexet vár, 1-et ad vissza


root.cpp:
#include "complex.h"
complex root(complex a, complex b, complex c) {}

main.cpp:
#include "complex.h" 
#include "root.h" // ezzel complex.h is include-olva, de sok fájlnál nem látni át
#include <iostream> // nem fordul, 2x complex.h, újradefiniálás -> #ifndef #define #endif


C: tömb méretét fordítási időben ismerni kell
int v[30]; // OK: ford idpben ismert
int s[30]; // for ciklus átírja egyikből másikba, 40 kell, v s egyzzen meg
int t[30]; // véletlenól 30 ugyanúgy

#define N30 // ; nem kell, v[N]  sorra ír hibát
#define K30 // át lehet írni 40-re
int v[N]; // preproc bemásolja 30-at
int s[N];
int t[K];


#define SQ(x) ((x)*(x)) // négyzetfv
// ...		// 5*5 -> fordítás előtt beírja a preproc, futás közben nincs fv-hívás
std::cout << SQ(5);
std::cout << SQ(2+3); // 2+3 * 2+3 = 11 -> x*x (zárójelek nélkül)
					  // ((2+3)*(2+3))
int a = 6;
std::cout << SQ(a++); // a == 8 (7 kéne)					MAKRÓK
					  // ((a++)*(a++)) == 42 == 6*7
// mellékhatása van, többször hivatkozunk a paraméterre
// a++ eredménye 6, közben növeli 7-re
// postfix operátor eredménye csökken/nő előtte


szövegátalakításra leírt eszköz:
#ifndef
#ifdef
#if
#elif
#else

compiler csomó paramétert átad preproc indítása...
OS, architechtúra, C++ -> leadja preproc h ne futás közben vizsgálja


3. összeszerkesztés:
--------------------
linker végzi: object-eket szerkeszt össze (ábra lentebb)

 CPP 		 ADA 		 C
a.cpp		a.adb		x.c			különböző nyelven írt korráskódokat is össze tud szerkeszteni
a.obj		s.obj		x.obj		más nyelvi eszközök is nyeli eszközök integr... technikája... ???
  v 		  v  		  v
		futtatható
nem ismeri namespace-t , fv-túlterhelést, stb

statikus linkelés: obj-eket...
dinamikus linkelés: futtatható + lefordított kódrészletek (dll/so)

futtatható: futáskor tölti be / keresi
			nincs minden megtalálva benne ???
lefordított kódrészletek: legyen megosztható több alkalmazás között
						  legújabb dll letöltése, új könyvtárral dolgozik
						  külső könyvtárban a hiba, nem kódban

dll hell: mindneféle dll verzió, nem jól működnek az appok, Win ...
		  nem tudja melyik app melyikkel kompatibilis