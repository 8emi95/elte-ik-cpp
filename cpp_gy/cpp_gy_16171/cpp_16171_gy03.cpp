//2016.09.28
//3. C++ GY

C++: const
C-ből: pointer - változó, melynek futás közben az értéke egy memóriacím
nullpointer: a program végrehajtásának egy szakaszán sehova se mutat
(nullpointer: 0)
nem szabad dereferálni

int x = 6;
int *p = &x; //* pointert jelenti
//x változó értékét lekérem
*p = 13;
std::cout << x;
			//13
p = 0; //nullpointer

pointer: - valid memóriacímre mutat
		 - nullpointer

*p = 5; //csak akkor valid ha p nem nullpointer
		//ennek megsértése futási idejű hibát okoz
if(p != 0) //csak akkor hajtom végrea dereferálást ha biztos h nem nullpointer
{		   //néha szokás nem ellenőrizni (KÉSŐBB)
	*p = 5;
}

const: futás közben nem megváltozó változó

const int step = 10;
int *p = &step; //fordítási hiba
//p pointer step memóriacíme legyen
int x = 3;
int y = 8;
int *ip = &y;
*ip = 2; //legális
ip = &x; //legális

const int *cip = &step; //cip azonosítón keresztül a mutatott érték nem változhat meg
cip = &y; //legális
*cip = 5; //fordítási hiba
//akkor se változhat meg ha int y típusú változóra mutat
std::cout << *cip; //ezt kezeli
				//9
cip = 0; //legális

int *const icp = &x;
//icp mindig ugyanoda mutat
*icp = 2; //legális
icp = 0; //fordítási hiba

const int * const cicp = &x;
//mindig ugyanoda mutat, cicp-n keresztül a mutatott érték nem változhat


Feladat: Másoljuk az std.input-ot az std.output-ra!
C/C++

villog a kurzor h gépeljünk vmit
beírjuk: alma\n 
kiírja: alma
beírjuk: korte\n
kiírja: korte
(eof) end-of-file karakter

Linux: cat (utility), Ctrl+D (eof)
DOS/Win: copy con, Ctrl+Z (megmondjuk programnak h nincs több input adat)

/*C:*/
#include <stdio.h>
int main()
{
	int i; /*másolás integer-en kersztül*/
	while ((i = getchar()) != EOF)
	{		/* =: operátor*/
			/* i = getchar(): kifejezés - típus
										- érték
										- mellékhatás */
		putchar(i);
	}
}

5/9*(i-32)
int

in x;
x+5

//kifejezés mellékhetása
int s = 3;
std::cout << s++; //postfix
			//eredmény: 3
			//mellékhatás: s értéke 4-re nőtt
s = 4;
std::cout << ++s; //prefix (hatékonyabb)
			//5
			//előbb s növelése direktben, megnövelt s-t adja vissza


/* C */
if (x = y) //x legyen egyenlő y
	//eredmény: amit értékül adtunk
	//x == y
{
	//...
}

x = y:
x = y; //értékadás
if (y != 0)


s = 4*x + 3*y;
//(s=4)*(x+3)*y
//precedencia: s = (4*x) + (3*y)
//= (értékadás) alacsony precedencia


i = getchar() != EOF ---> i = (getchar() != EOF)

'a' - C: int
	- C++: char


//C++
#include <iostream>
int main()
{
	char ch;
	while (std::cin >> ch) //mellékhatás: ch-ba bekerül a beolvasott karakter
	{					   //eredmény: std::cin - értékeljük ki h igaz-e
		std::cout << ch;
	}
}

std::istream -> log. felt.
				konverziós operátorral rendelkezik: pointerré konvertálódik
bool b = std::cin;


//kiíratás láncba köthető
std::cout << i << "Fahr" << fahr2cels(i);
	std::cout
		std::cout
				std::cout
std::cin >> x >> y;


class Foo
{
public:
	Foo(int i) //konstruktor
	{
		//
	}
}

void g(Foo s)
{
	//
}

g(5); //lefordul
//g(5) -> Foo(int i)
//Foo(int i) -> void g(Foo s)


if(x = y)
{
	//
}
->
x = y;
if (y != 0)
if (x) //x != 0
int *p;
...
if (p); //p != 0;


complex c;
...
if (c) //c nem komplex nulla
class complex
{
private:
	int re, im;
public:
	operator bool()
	{
		return !(re == 0 && im == 0)
	}
}


std::istream -> log. felt.
				konverziós operátorral rendelkezik: pointerré konvertálódik
													nem boolra, mert...

//standard outputre standars output kiíratása
std::cout << std::cout;
			//konvertálódik pointerré, memóriacímet kapunk


nem boolra konvertálódik, mert:
int s;
std::cin << s; //ha lenne bool konverziós operátor akk nem lenne fordítási hiba
//boollá konvertálva << valid operátor, bitshift-elés operátor
//10101110 << 2: 10111000
//pointer és szám között nincs értelmezve ilyen művelet -> fordítási hiba