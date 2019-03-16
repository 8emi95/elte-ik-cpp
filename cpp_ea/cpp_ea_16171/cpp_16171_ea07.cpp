2016.10.24.
7. C++ EA

http://patakino.web.elte.hu/pny2/alprogram.pdf

C++ referencia:
int i = 3; // allokál tárterületet, belekerül a 3			i, r, cr
int &r = i; // álnév										[3]
int *p = new int(3);			//	x
int &x = *p;					//	[3]
								//	^p
const int & cr = i; // konstans referencia: olyan álnév a tárhelyen amin keresztól nem változik meg...

C++ referencia:
- nincs nullreferencia
Java referencia:
- mint egy C++ ref
- nem kell referálni
- mint egy C++ pointer (amit nem kell dereferálni)
C/C++ pointer:


std::vector<inr> &read(); // lefordul
{
	std::vector<int> v;
	// ...
	return v;
}


int v[] = {8, 2, 7, 3};
reverse(v, sizeof(v)/sizeof(v[0])); // tömbméret nélkül nem tud átadódni


eredmény szerinti:
------------------

void f(int x) // saját nyelv: eredmény szerint van átadva
{
	//
}

int y;
f(y); // f lokális változója x, fv-hívás végén másolódik bele y-ba x


név szerinti:
-------------

g(3); // g név szerint veszi át
	  // olyan mintha érték szerint venné át
int i;
g(i); // cím szerinti
g(i++); // mellékhatással rendelkező pm
		// többször kiértékelheti


------------------------------------------------------
Deklarációk:
------------------------------------------------------

fordítási egységek:
-------------------
a.cpp:
int x; // definíció
void f(int i) // definíció: biztosítani kell h egy helyen van definiálva (one definition rule)
{ ... }

b.cpp: // a.cpp tartalma nem ismert b.cpp fordításakor
void f(int); // deklaráció: t9bb helyen lehet
			 // jellemzően headerből
extern int x;
f(3);


inline fv:
olyan egyszerű h nem akarjuk linkelni(?)
fv-def nem lehet headerben (?)