2016.09.21.
2. C++ GY

/* Hello World C-ben */
/*	ez az egy komment volt C-ben
	DRY (don't repeat yourself), ami látható azt nem kell kommentezni
	inkonzisztenssé válik a kóddal, ha túlhasználjuk
 */
#include <stdio.h> /* Hello World enélkül is lefordul C-ben, C++ megszüntette h fv-t lehessen hívni deklarálás nélkül/ */
int main()
{
	printf("Hello World!\n");
	return 0;
}

/*
/*...*/ -> ez lesz a vége, nem egymásba ágyazható
*/ 		// egysoros megoldja

// C++-ban (egysoros komment bevezetése)
#include <iostream>
int main()
{
	std::cout << "Hello World!" << std::endl;
	// return 0; // elhagyható, automatikusan 0-t ad vissza, minden más NEM voidnál kell
}

std egy obj szabványkönyvtárban, minősített neve van
std névtérbeli cout
:: operátor
using namespace std; // minősítés nélkül, ekkor nem kell "std::" a "cout" elé

namespace/névtér:
-----------------
C 2 db f neváű fv-t nem különbözteti meg, ha az egyik 1 a másik 2 pm-t vár
OpenGL: mindne f gl-lel kezdődik
PVM: pvm..., pvm_send() // egyedi prefixek
Java: package, import
using direktíva -> cout egyértelműen std-beli, lehet írni saját típust, bővíthetőek nyíltan

java util*
import java...

using std::cout; // csak ezt az egyet nem kell, többit ki kell írni

namespace A
{
	void f() {...} // A:f() ha átírom g-ra akk nem kényszeríti ki a compiler h kommentben is át legyen írva
}
namespace B 						// különböző f()-ek
{
	void f() {...} // B:f()
}
// mndkét using kiírva, f-re hivatkozva nem tudja melyik


Fahrenheit-Celsius konverzió:
-----------------------------
[-20,140] 10-esével végigmegyünk (C/C++)
-20 °F		°C				x -> 5/9(x-32)
-20 °F		°C
  ...
-20 °F		°C

/* C */
#include <stdio.h>
int main()
{
	int lower = -20; /* ha át kell írni akk nem kell gondolkodni hol 	} */
	int upper = 140; /* 												} memóriában kell tartani (*) */
	int step = 10;   /* 												} */
	/*   ˇinicializáló lépés üres, i deklarálva */
	for (; i <= upper; i += step)
	{ /* formázó karakterek a változók kiíratásához */
		printf("%dFahr\t%fCels\n", i, 5./9*(i-32));
	} 						/* 	   ˇ1. szám   ˇ2. szám */
	return 0;
} /* lineáris fv matematikai szempontból mindenre 0 °C-t ad így */
/*
%d: decimális formátumban jelenik meg a továbbiak közül az első
\t: tabulátor
\n: sor véfe

printf("%dFahr\t%dCels\n", i, 5/9*(i-32));

5/9 = 0 -> kerekítés
int (/: bináris operátor) int -> egész művelet


printf("%dFahr\t%dCels\n", i, 5./9*(i-32))

5./9
double/int
int-et double-lé konvertálja
lebegőpontos osztás lesz
ugyanaz: 5/9.
		 5.0/9
		 5.0/9.

5./9 -> 793625841... -> formázó karakterek miatt
		638247153...	%d egész szám ábrázolás, nem lebegőpontos

%dFahr, i -> futási idejű paraméterek
			 2. %d double, compiler nem kényszeríti ki, warning-ot ad
			 lehet h nem is látja a 2.-at
2. %d -> %f
 */


/* (*) include ... */
#define LOWER -20	/* } */
#define UPPER 140	/* } bemásolja preprocesszor szinten */
#define STEP 10		/* } */
#define FAHR2CELS (x)(5./9*(i-32)) /* sok soros kódnál nem emlékezni h hol volt */
int main()		/* fv-hívás kültséges, így nem kell*/			/* makró */
{
	int i = LOWER;
	for (; i <= LOWER; i += STEP)
	{
		printf("%dFahr\t%fCels\n", i, FAHR2CELS(i));
	}
	return 0;
}

fahr.cpp:
// C++
// nyelv részeként kezelhető megoldás preprocesszoros szövegátalakítás helyett
#include <iostream>
inline double fahr2cels(double x) // inline ajánlás compiler részére
{								  // fv-hívás helyére fv-törzet helyettesíti, de fv és nem szövegszerű helyettesítés
	return 5./9*(x-32);			  // kerülhet headerbe, nem lesz belőle object-kód, nem lehet összeszerkeszteni, preproc hajtja végre
}
// fájl elején állhat inline fv, másik fájlban nemtom használni
int main()
{
	const int lower = -20; // define-ok helyett, nem változhat meg (const)
	const int upper = 140; // lower = 30; compiler szól (???)
	const int step = 10; // const nem könnyű nyelvi eszköz
	// ciklusváltozó, fv-ben kéne csak látszódjon
	for (int i = lower, i <= upper, i += step)
	{			// i: nem kell formázó string, C-ben string literal-ba compiler nem szól bele
		std::cout << i << " Fahr\t" << fahr2cels(i) << " Cels" << std::endl;
	}								// tudja h double
} // C++-ban típus dönt, nem formázó string


változótípus: pointer
---------------------
értékük futás közbeni memóriacím.

void f()
{
	int i = 5;
	int *p = &i; // *: p memóriacímet ír le
				 // &i: mi i-nek a memóriacíme?
	std::cout <<p; // 0xb2a4eea4 (kékhalálnál megjelennek ilyenek)
				   // 0x: hexadecimális
	*p = 3; // i
			// [5] -> 3 lesz
			// ^
			// p
			// []
	// PAPÍROS RAJZ ^
	std::cout <<*p; // i = *p = 3
}
