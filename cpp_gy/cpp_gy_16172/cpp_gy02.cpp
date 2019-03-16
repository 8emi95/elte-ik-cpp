2017.02.22.
2. CPP GY

/*
/* */ -> ez a záró komment
/* */
*/

// C++ bevezetett egysoros kommentet


/* 1970: Hello World C-ben */
#include <stdio.h>
int main()
{
	printf("Hello World!\n");
	return 0;
}

// c++ban nem tudunk meghívni nem deklarált fv-eket
// Hello World C-ben
#include <iostream>
using namespace std; // "?" környezeti változóa kerül (???)
int main() // csak a main esetében automatikusan return 0; ha nem írjuk ki
{
	cout << "Hello World" << endl;
}


#include <iostream>
int main()
{
	std::cout << "Hello World" << std::endl;
}



névtér / namespace: logikai csoportosítás (C-ben nem létezett)
OpenGL: gl_ (fv)
PVM: pvm_ (pvm_send(...) fv)

std névtér: tartalmaz vector adatszerkezetet... stb



namespace A // fordítási egységben
{
	void f() {...} // A::f()
}

void A::f(); // deklaráció (headerben?)

namespace B
{
	void f() {...} // B::f()
}

using namespave A;
f(); // A-beli f-et hívja meg

using namespave A;
using namespave B;
f(); // fordítási hiba, nem tudja melyik f kell
B::f(); // javítás


Fahrenheit-Celsius konverzió:
-----------------------------
[-40,120] 10-esével végigmegyünk
-40 °F == ? °C
-30 °F == ? °C
...
120 °F == ? °C

x -> 5/9*(x-32)


#include <stdio.h>
int main()
{
	int lower = -40;
	int upper = 120;
	int step = 10;
	int i = lower;
	for (; i <= upper; i+=step)
	{
		printf("%d Fahr == %d C\n", i, 5/9*(i-32));
	}
}
->
-40 Fahr == 0 C
-30 Fahr == 0 C
...
120 Fahr == 0 C

5/9*(i-32)
int/int = 0

5./9*(i-32) // v 5.0
double/int

->
-40 Fahr == 398436714 C
-30 Fahr == 62384531 C
...
120 Fahr == ... C

printf("%d Fahr == %f C\n", i, 5/9*(i-32)) // 2. %d -> %f
-> JÓ


#include <stdio.h>
#define LOWER -40
#define UPPER 120
#define STEP 10
#define FAHR2CELS(x) (5./9*((x)-32))
int main()
{
	int i = LOWER;
	for (; i <= UPPER; i+=STEP)
	{
		printf("%d Fahr == %d C\n", i, FAHR2CELS(i));
	}
}


#include <iostream> // input/outputk kezeléshez, típusbiztos
inline double fahr2cels(double x) // fv-hívást fv-törzsre cseréli
{
	return 5./9*(x-32);
}
int main()
{
	const int lower = -40; // const értéke nem változik
	const int upper = 120;
	const int step = 10;
	for (int i = lower; i <= upper; i+=step)
	{
		std::cout << i <<" Fahr == " << fahr2cels(i) << " C" << std::endl;
	}
}


C/C++ pointer: futás közben az értéke memóriacím
--------------

int i = 6;
int j = 2;
int *p = &i; // címképzés

// i[6] <- p
// j[2]

*p = 8; // dereferálás
// i[8]
std::cout << i; // 8
p = &j;


int *p = &step; //fordítási hiba
*p = 20;


int x = 4;
int y = 7;
const int s = 6;
int* ip = &x;
// x[4] <- ip
// y[7]
// s[6]
*ip = 5;
ip = &y;
*ip = 2;
cosnt int* cip = &s; // a cip-n keresztül nem változtatható meg az érték
*cip = 1; // fordítási hiba
// x[5] <- ip
// y[7]
// s[6] <- cip


cip = &y; // ok
y = 4; // ok
*cip = 3; // nem fordul le
int *const icp = &x; // icp minidg ugyanarra a változóra mutat
icp = &y; // fordítási hiba

const int* const cicp = &y;
// cicp mindig ugyanoda mutat
// cicp-n keresztül a mutatott érték nem változhat