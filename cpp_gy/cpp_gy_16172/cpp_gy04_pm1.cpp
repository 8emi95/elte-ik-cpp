2017.03.08.
4. CPP GY

+/-:
#include <iostream>
int main()
{
	double d = 9 / 2;
	std::cout << d / 10;
}
lefordul?
ha ne,, akk mi lehet az oka?
ha igen, akk mi történik futás közben?

válasz:
lefordul
int/int -> 4
d == 4.0
d / 10 == 4.0

**************************************************************************

Tömbök:
-------
- méretét fordítási időben ismerni kell
int a[5];
int v[] = {3, 8, 4, 1, 2};	// 5 -> v[] (tudni fogja h 5elemű)
// v
// [3][8][4][1][2]
// v[0]

int a[5] = {3, 8, 1, 2}; // lefordul
// 5elemű tömb, a[4] létező elem nem ismert értékkel

int b[3] = {1, 2, 3, 4}; // fordítási hiba

									// int
for (int i = 0; i <sizeof(v) / sizeof(v[0]); ++i)
{
	++v[i]; // jól működik
}


void inc(int *a, int n) //(int a[])
{
	for (int i  = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{				// függetle a tömb hosszától <- sizeof(a) / sizeof(a[0])
		++a[i];
	}
}

inc(v, sizeof(a) / sizeof(v[0]));

int *p = v;


pointer-aritmetika:

// v
// [3][8][4][1][2]
// ^  ^
// p++

p++; // } eggyel nagyobb indexűre lépteti a pointert
++p; // }

p--; // } eggyel kisebb indexűre lépteti a pointert
--p; // }


int *q = v + 2;
v[1] = 5;
*(v + 1) = 5;
*(1 + v) = 5;
1[v] = 5; // lefordul
// y + 3 == 3 + y

std::cout << "Hello" + 1; // "ello" 1. karaktert nem írja ki mert annyival előrébb ugrunk az egybefüggő tárterületen
std::cout << 1["Hello"]; // 1["Hello"] = e

"Hello": ['H']['e']['l']['l']['o']['\0']
std::cout << "Hello";


int *q = v + 2;
p = v;		// ˇ2
std::cout << q - p; // p-t mennyit kell léptetni h elérjük q-t?

p < q;  // } p kisebb indexűre mutat-e, mint q
p >= q; // } egybefüggő tárterülettel dolgozunk
p == q; // ugyanaz a cím-e, ugyanoda mutatnak-e?

C: <string.h>
C++: <cstring>
strlen: megadja h egy C string hány karakterből áll



int strlen(char *p)
{
	char *q = p;
	while (*q != '\0')
	{
		++q;
	}
	return q - p;
}

strlen("ab");
// ['a']['b']['\0']
// ^p			^q
// q - p == 2


void g()
{		// valid konv
	char *msg = "blablabla";
}

void fv()
{
	char ch = 'a';
	// strlen(&ch);
	strlen(0); // program elszáll, oprendszer leállítja <- std::string s(0);
}



int strlen(char *p)
{
	char *q = p; // 0...0
	while (*q = '\0') // hamis
	{
		++q; // \0 == 0
	}
	return q - p;
}

void f()
{				// str[9] <- 9
	char str[] = "kukumuku"; // módosítható tömb
	int i = strlen(str); // 0
	std::cout << str; // üres string
	std__cout << str + 1; // ukumuku
}

// str
// ['k']['u']['k']['u']['m']['u']['k']['u']['\0']
// ^p^q

// ['\0']['u']['k']['u']['m']['u']['k']['u']['\0']

void g()
{
	char *str = "almafa";
	strlen(str); // oprendszer leállítja a programot
	strlen("abc"); // const char[4]
}

int strlen(char *p)
{
	char *q = p;
	while ('\0' != *q) // operanduscsere
	{
		++q;
	}
	return q - p;
}

int strlen(const char *p)
{
	const char *q = p;
	while (*q != '\0')
	{
		++q;
	}
	return q - p;
}