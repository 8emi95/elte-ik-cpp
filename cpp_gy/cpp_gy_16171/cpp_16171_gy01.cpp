2016.09.14.
1. C++ GY

számonkérések:
- 3 db +/-, pár perc, nagyobb témakörök lezárta után kb
  hiányzásnál előzetes jelzés -> lehet javítani (utólag jelezve nem)
- vizsga:
	- elméleti: +/- állásból indul, 15 kérdés/pont, max 18 min 8, ABCD
	- gyakorlati: algoritmikus gondolkodást igénylő feladat lehet
				  20 min, 50 sor, 4 nehezebb sor rutinosoknak
				  összesen 3h
				  adatszerkezet implementálása, főprogram kikommentezve, commandline
				  szóban védés.
				  írott, nyomtatott, net
				  korábbi beugrókból helyeset cseréli, hibásat bent hagyja
GYAKON SZEREPLŐ KÓDOK KIPRÓBÁLÁSA!

bead: opcionális, félév 2. felében (volt h vizsgafeladatot ebből csinálta, volt h semmi köze nem volt hozzá)
segédanyagok: könyvek (EA)
tematika: C++ megértése, összehasonlítás C-vel és Javával


********************************************************************************************************************


----------------------------------------------------
Programok fordítása, futtatása: C/C++
----------------------------------------------------

fordítóprogram: - magas szintű nyelvi konstrukciókat kifejezze CPU nyelvén
(compiler)		- ha nem talál hibát a kódban (???)

fordítás lépései:
1. preprocesszálás: szövegátalakítás (magas szintű C++ kód az eredmény)
					#include
					#define
					#endif
2. nyelvi fordítás
3. összeszerkeztés: linker

többen dolgoznak a programon -> fordítási egységekre bontás, külön időben fordulnak le, nem látja egyszerre az összeset

a.cpp	...		n.cpp			hibák: #kukumuku -> nincs ilyen #
 ˇ1. preproc	 ˇ
a'.obj			n'.obj
 ˇ2. fordítás	 ˇ
a.obj	--->	n.obj 			- ambiguous reference: nem tudja melyik...?
	object/tárgykód 			- undefined reference: hivakozás valódi implementációját nem találja
 ˇ 		 3. 	ˇ
 futtatható állomány (nem muszáj csinálni)

(dinamikus linkelés: futás közben hívhat meg DLL-eket)


faktoriális fv: imperatív (jobb)/rekurzív
---------------					 --------

fac.cpp:
/*int fav(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n*fac(n-1);
	}
}*/ // undefined reference lesz (a.cpp)
-> fac.obj

a.cpp:
#include <iostream>
int fac(int); // egészet vár és ad vissza
int main()
{
	std::cout << fac(5);
}
-> a.obj


gcc/g++:
--------
g++ a.cpp b.ccp c.obj ... -> a.out (Linux) / a.exe (Windows)
-w -wall // figyelmeztetés bekapcsolása

int i = -3;
unsigned int j = 1; // nem lesz negatív soha
if (i < j)
{
	std::cout << "ok";
}
else
{
	std::cout << "wtf"; // wtf-et fog írni, 2 int v 2 unsigned int között tud
}					   // int -> unsigned int konvertál, előjelet "bebillenti" (?), nagy szám lesz

-pedantic -ansi // szabványos kód/működés