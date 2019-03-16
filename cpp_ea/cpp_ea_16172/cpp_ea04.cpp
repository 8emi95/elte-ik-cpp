2017.03.08.
4. CPP EA

tokenizálás:
------------
- kulcsszavak
- azonosítók
- konstansok
- konstans szövegliterál
- operátorok
- szeparátorok

15 -> típus: int
sizeof(int): implementáció-függő
int - előjeles
unsigned int - előjel nélküli

sizeof(short) <= sizeof(int) <= sizeof(long)
sizeof(T) == sizeof(unsigned T) == sizeof(signed T)

char: egység
sizeof(char) = 1 // ekviv
implementáció-függő

6L -> long
9U -> unsigned int
12UL -> unsigned long, érték: 12
0x24 -> int, hexadecimális (0x)

0x15L -> long, konstans, értéke: 21

oktális (8-as szr.)
O23 -> értéke: 19


lebegőpontos konstansok:
------------------------
1.5 -> double
// (-1)^0˙15*10^(-1)
// pont = szorzás?
15e-1 -> ugyanaz (15*10^(-1))

sizeof(float) <= sizeof(double) <= sizeof(long double)
sizeof(char) <= sizeof(short)
sizeof(char) <= sizeof(bool)
true, false logikai értékek

char típus előjelesség: nem definiált, implementáció-függő

operátorok, kifejezések:
=
==
++
||
&&
& -> címképzés
  -> bitenkénti és

a = (4*b)+(9*c)
			=
		a		+
			*		*
		4	  b  9		c

a = 4*(b+9)*c

legmagasabb precedencia:
::
.

legalacsonyabb precedencia:


(a=4)*b // (a=4) eredménye mellékhatás

int x = 3;
std::cout << x++; // 3
// x == 4
std::cout << ++x; // 5
// x == 5

std::cout << x + y; // x, y változatlan marad


kötések:
--------
- balról
- jobbról

int a, b, c;
a = b = c = 6; // jobbról köt -> a = (b = (c = 6))
// <-  <-  <-
a = b + c + 6; // balról köt -> a = ((b + c) + 6)

std::cout << "Hello"; // eredmény: std::cout


szokásos aritmetikai konverzió:
-------------------------------
std::cout << 13/10; // 1 (int/int -> / int művelet)
std::cout << 13/10.0; // 1.3 (10 double, 13 double-lé konvertálódik)

// bekarikázott x
a (x) b -> ha a és b típusa eltér, akk konvertálni kell az egyiket
- ha az egyik operandus long double
- kül, ha az egyik operandus double
- kül, ha az egyik operandus float
- kül, ha az egyik operandus unsigned int
// ...
- kül, ha az egyik operandus long, a másik unsigned int
sizeof(int) == sizeof(long) -> mindkettő unsigned long-gá konvertálódik
sizeof(int) < sizeof(long) -> long-gá konvertálódik
- kül, ha az egyik operandus long
- kül, ha az egyik operandus unsigned int -> a másik konvertálódjon unsigned int-té
- kül, minden int-tá konvertálódik

bool:
nem 0 -> true -> 1
	0 -> false -> 0

5L + 3 -> long (int konvertálódik long-gá)


kifejezések sorrendje:
----------------------
int v[3];
int i = 0;
v[i++] = i; // ; szekvenciapont garantálja h i == 1
// i++ = 0

szekvenciapont:
;
&&
||

int i;
if (i++ || i == 5) {...}
//			˘i megnövelt


bool f()
{
	std:: cout << 'f';
	return false;
}
bool g()
{
	std:: cout << 'g';
	return true;
}
bool h()
{
	std:: cout << 'h';
	return false;
}

if (f() == g() == h()) //ghf
{
	std::cout << 't'; // garantált
}
else
{
	std::cout << 'f';
}


if (a || b) // b-t csak akkor értékeli ki, ha a hamis

std::cout << (x, y); // y-t írja ki
f((1,2)) // void f(int x); -> 2