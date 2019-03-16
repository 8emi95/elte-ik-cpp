2017.02.15.
1. CPP GY

14:00-15:30

számonkérés:
3 +/-

mai világ elment commandline irányba, sokszor nem GUI-kkal dolgoznak

fodítás/futtatás:
--------------------
- CPU: gépi kódot tud futtatni
(abstraction penalty)
- fordítóprogram: magas szintű forráskódból alacsony szintű kódot készít, közben hibákat detektál
- interpretált nyelvek: a forráskód feldolgozása és végrehajtása nem különül el (python, javascript)
- byte-code-alapú nyelvek: (Java - magas szintű kódra fordul)
fordítás - magas szintű kód
futtatás - magas szintű bájtkód interpretálása

C/C++ programok futtatás:
-------------------------
0: forráskód gépelése
1: preprocesszálási fázis - szövegátalaítás
2: nyelvi fordítás - cpp -> obj (object / tárgykód: lefordítótt kódrészlet)
3: összeszerkesztés - linker


a.cpp:
void f() { ... }
-> a.obj

b.cpp:
void f() { ... }
-> b.obj

c.cpp:
void f();
void g()
{
	f(); // ekkor még nem fordul le
}
c.obj

linker: a.obj b.obj c.obj - ambiguous reference
linker: c.obj - undefined reference

gcc/g++
C/C++

g++ hello.cpp (bekonfigurált preprocesszorral és bekonfigurált linkerrel végrehajtja) -> a.out/a.exe

-W -Wall: figyelmeztetések (magas fokra?)

int i = -3;
unsigned int j = 2; // unsigned: van benne egy olyan bit, ami negatív számokat tudja kezelni ???
if (i < j)
{
	std::cout << "ok";
}
else
{
	std::cout << "wtf";
}
-> wtf

int és unsigned int között nincs megírva hasonlítás.


-pedantic -ansi
int k;
std:cin >> k;
int v[k]; // NEM szabványos C++, C99 engedélyezte
// ha compilerben változás történik az megkönyíti az átalakítást (?)

-ansi // compilertől várja el h teljesen szabályosan működjön (?)

-c // ne induljon el a linker, csak obj-ek jöjjenek létre

-save-temps // megőrzi a közbünső fájlokat (?)

-On (n = 0, 1, 2, 3, s) optimalizáció


int v[5];
for (int i = 0; i < 5; ++i)		//} v[0] = 0
{								//} v[1] = 0
	v[i] = 0;					//} v[2] = 0
}								//} v[3] = 0
								//} v[4] = 0

-g // debug infók