2016.10.05.
4. C++ GY

------------------------------------------------------------
Tömbök, tömbök és pointerek kapcsolata:
------------------------------------------------------------

char *p = "Hello"; // 'H', 'e', 'l', 'l', 'o', '\0'
				   //  ˇ(p rámutat H-ra)

tömbök mindig konvertálódnak első elemre mutató pointerré.


int s[4] = {1, 5, 2} // lefordul, 3 elemmel lehet inicializálni egy 4-elemű tömböt, 4-elemű tömböt hoz létre
int x[2] = {1, 5, 2} // fordítási hiba

3		5		1		8		2
v[0]							v[4]
<-------------------------------> // megnézhetjük h mekkora tárterület
		sizeof(v)

int v[] = {3, 5, 1, 8, 2} // inicializálás alapján compiler látja h 5-elemű tömb
/*
for (int i = 0; i < sizeof(v)/sizeof(v[0]); ++i) // megtudjuk h hányelemá a tömb
{
	++v[i];
}
*/
inc(v); // inc(&v[0])
		// tömb mindig a legeső elemre mutató pointerré konvertálódik, tömb 0. elemének címét adjuk át fv-nek
inc(v, sizeof(v)/sizeof(v[0])); // kül elvesztenénk azt az infót h meddig tart
//  ˇ----------^				// ha változik a tömb típusa akk a v[0] ugyanúgy következetes marad

//függvénnyel
void inc(int v[]) // inkrementáló fv
{
	for (int i = 0; i < sizeof(v)/sizeof(v[0]); ++i) // sizeof(v): független a tömb hosszától
	{									// int		 // v pointer...
		++v[i];
	}
}

pointeraritmetika				// s
int s[] = {3, 4, 8, 1}; 		// 3	4	8	1
int *p = s;						// ^p (p 3-ra mutat)
s[1] = 5; // p[1] = 5;			//  ++ ^p
// p = 5; fordítási hiba
// p = 0; nullpointer lesz, műküdik
++p; // eggyel nagyobb indexűre lépteti p-t
p++;
--p; // eggyel kisebb indexűre lépteti p-t
p--;

s[2] = 7;
*(s+2) = 7;
*(2+s) = 7;
2[s] = 7; // C/C++: oké
// csak a két operandus van felcserélve, kommutatív
std::cout << 1["Hello"]; // output: e

double d = 3.5;
d+1.1
1.1+d

p += 3;
p -= 2;

int *q = s+3;
std::cout << q-s; // s-től mennyit kell lépni h elérjük q-t
			//3		kivonás 2 pointer között is valid

int *a = s+1;
int *b = a+1;
a == b // ugyanoda mutat-e a és b
a != b
a < b // a kisebb indexűre mutat-e, mint b	}	2 pointernek egybefüggő tárterületre kell mutatnia
a >= b //									}

char *s = "blabla"; // 7-elemű tömb
string.h, cstring -> ???
strlen(s) == 6 // hány karakterből áll a string

int strlen(char *s) // const char-ok elé (itt + első sor)
{						  //-1
	// if (s == 0) { return 0; } // lehetne, de C nem teszi meg, mert stringkezelő fv-eket annyira sokat használjuk h nem akarja megfizettetni h mindig lekérdezzük
	char *p = s; // ltrehozunk még egy pointert, kezdetben ugyanoda mutat
	while (*p != '\0')	// strlen(0) - OS leállítja a programot
	{	// *p = '0\' -> véletlenül lemarad a !, értékadás lesz 
		// '0\' = *p -> fordítva írva jobban kiszűri a compiler
		++p;			// strlen("Hello")
	}					// "A" -> 'A'	'\0'
	return p-s;			//		   ^s 	^p 				p-s == 1
}

char msg[] = "kukumuku",
int i = strlen(msg); // ha ez az int strlen(char *s), ahol while-ban értékadás
// i értéke: 0
//msg:	\0	n 	k 	u 	k 	u 	m 	u 	k 	u
//		^s^p
std::cout << msg; // üres string
strlen("text"); // konstansoknak fenntartott tárterületre kerül, const char[5] tömb
				// OS leállítja a programot


F: std input-ot std output-ra másolni kisbetűből nagybetűre konv-val! //C++

//		//65				//97
// := .., A, B, ..., Z, ..., a, b, ...z,...
//								ˇchar

#include <iostream>
int main()
{
	char ch;
	std::cin >> std::noskipws;
	while (std::cin >> ch)
	{
		std:: cout << (ch >= 'a' && ch <= 'z' ? ch-'a'+'A' : ch);
	}				// ch >= 'a' && ch <= 'z': logikai feltétel
}
// -: int  }
// +: int  }  ch-'a'+'A': int
// ch: int }
// egész "felt ? igaz : hamis" int lesz

// aAbB
sd::cout << static_cast<char>(ch >= 'a' && ch <= 'z' ? ch-'a'+'A' : ch);
// AABB -> ezt adja így vissza

f(felt ? a : b, felt ? c : d)