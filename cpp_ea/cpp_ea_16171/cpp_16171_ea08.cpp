2016.11.07.
8. C++ EA

//

double are, aim; // lebegőpontos/komplex szám
double bre, bim; // még egy
// névkonvencióval próbálunk utalni arra h összetartoznak (_a_re, _a_im)

double add(double are, double aim) {}

void add(double are, double aim, double bre, double bim); // mi a visszatérési érték? void?


struct complex // rekordtípus
{
	double re, im; // mező
};
		   // re im
complex c; // [][]
c.re = 4.6;
c.im = 3.2;
// jobban ki van fejezve h összetartoznak, memória szintjén is, kevesebb az azonosító is
comlex d;

complex add(complex a, complex b) {} // vissza tud adni complex számot



#include "date.h"
void f()
{
	date d; // nyugodtan lehet lokális változó
}

// referenciaszemantika?


class complex;
complex c* = 0; // ugyanannyi bájt mint bármelyik pointer, attól még h nem tudni mekkora területre mutat (?)

void f()
{
	date d; // 2000.01.01 konsi alapján *date.h*
	d.get.year(2013); // objektum.függvénynév.paraméterek
					  // pointeren keresztül adódik át
					  // set.year(2013, &d)
	// this típusa: date * const this
	//				végig arra at objektumra mutasson
	std::cout << d.get.year(); // get.year() megkapja a d-t, this néven adódik át, nem látni direktben
							   // get.year(&d) memóriacímet/pointert kap
	// return year; = this -> year
}
// konstruktro lefutása után teljes értékű, használható objektum...


date today(2016, 11, 7); // konstruktor *date.h* nem kötelező 3-at megadni
date x(2016, 5); // május 1. lesz
date y(2016);

inline fv: mindenhova bemásolódik a kódja és lefordítódik

date a("2016.11.4");

const date birthday(1982, 2, 26)
std::cout << birthday.get.year(); // get.year(birthday)
								  // date * const this


date b;
b.set.year(2015).sest.month(9).set.day(7);
// date& visszatérés, dátummal térünk vissza, *this, visszakapjuk azt az objektumot amin eredetileg meghívtuk a tagfvt-t
// meg lehet hívni rajta set.month műveletet
++b;
b++; // b.operator++(0);


date a(2015, 12, 6);
date b(2016, 1, 3);

if(a < b) // ezt akarjuk leírni/vizsgálni
// ez egy tagfv, < egy a-n meghívott operátor
// a.operator<(b)
// operator<(a,b)

class date
{
public:
	bool operator<(date b) const
	{
		// ...
	}
};


if (2016 > a)
{
	2016.operatpr>(a); // "2016.1." == ...
}

if (a < 2016) {} // date(2016)
// a.operator<(2016);
// operator<(a,2016);