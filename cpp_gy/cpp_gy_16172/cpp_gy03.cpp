2017.03.01.
3. CPP GY

F: másoljuk standart inputot (std. input) a standard outputra (std. output)

almafa\n
> almafa
x y z\n
> x y z
(eof)

DOS/Win: copy con, Ctrl+Z
Linux: cat, Ctrl+D
C/C++
int x, y;
x + y -> kifejezés
x == y -> kifejezés
x = y -> kifejezés

x = 3 * y + 8 * w; // értékadás precedenciája alacsony
(x = 3) * y + 8 * w; // nincs értelme, csak számolgatok a végén

#include <stdio.h>
int main()
{
	int ch;	// ˇértékadás operátor
	while ((ch = getchar()) != EOF)
	{		//	ˇ
		putchar(ch); // eredmény: mi volt a beolvasott karakter
	}				 // mellékhatás: ch-ban eltárolásra kerül a beolvasott karakter
}

#include <iostream>
int main()
{
	char ch;
	std::cin >> std::noskipws;
	while (std::cin >> ch) // kiértékelem: std:: cin -> std::i?t???
	{
		std:: cout << ch;
	}
}

std::cin >> ch
- melléhatás: ch-ba bekerül a beolvasott karakter
- eredmény: az std::cin ...

std::cout << i << " Fahr " << fahr(i);
std::cout	<
	std::cout		<

int x, y;
std::cin >> x >> y;
std::cin 	<

C++: konverziós operátor
class Foo
{
	int x;
public:
	operator bool()
	{
		return x >= 0;
	}
};

Foo f();
if (f) { ... } // f.x >= 0
//  ˇoperator bool()
bool c = f; // -> operator bool()


std::cout << std::cout; // standard outputra kiírjuk a standard outputot
		// > 0x28a4x310
		// pointer formátum, 0x - hexadecimális szám


int a = h;
int *p = &a;
*p = 7; // p -> a[7]
// pointer: lehet h épp sehova se mutat (nullpointer)
p = 0; // p sehova se mutat
if (p) // p nem nullpointer
{
	*p = 3;
}

// ha az std::cin nem pointerré konvertálódna:
int s;
std::cin << s;
// std::cin -> pointer

aAbB123
AAAB123
kisbetű -> nagybetű átalakítással
C++



#include <iostream>
int main()
{
	std::cin >> std::noskipws;
	charch;
	while (std:cin >> ch)
	{
		std::cout << (ch >= 'a' && ch <= 'z' ? ch - 'a' + 'A' : ch);
	}
}

aAbB -> 6565666...
ch - 'a' + 'A' -----------------------------------> int
ch -----------------------------------------------> char
(ch >= 'a' && ch <= 'z' ? ch - 'a' + 'A' : ch) ---> int

static_cast<char>(ch >= 'a' && ch <= 'z' ? ch - 'a' + 'A' : ch)
// elé kell rakni h rávegyük a fordítót h char-ként kezelje

(T)x: x-et cast-oljuk T típusúvá (x: változó/kifejezés/fv-hívás) // C++-ban nem javasolt

C++ castok:
-----------
- static_cast
- dynamic_cast
- reinterpret_cast	} veszélyesek
- const_cast		}

(T)f()
Y f() { ... }