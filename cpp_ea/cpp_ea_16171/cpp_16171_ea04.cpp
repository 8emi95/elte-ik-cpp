2016.10.03.
4. C++ EA

Eml.: tokenek
- kulcsszavak -
- azonosítók -
- konstans szövegliterálok -
- konstansok
- operátorok
- szeparátorok

7 -> típus: int (előjeles, nem mondja meg hány byte-on van ábrázolva)
	 érték: 7

 1 = sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long)
    ˇ
nyelv egysége
(= ekviv)
char: nem  garanált az előjelessége
singed/unsinged char

6.7 -> típusa: double

nem mondja meg hány byte-on kell ábrázolni, hanem van sizeof
sizeof(float) <= sizeof(double) <= sizeof(long double)
6.7f -> típusa: float
6.7L -> típusa: long double
67e-1 = 67*10^(-1)
18e-2f -> típusa: float

sizeof(T) == sizeof(unsingedT) == sizeof(singedT)

sizeof(bool) <= sizeof(long) // megegyezhetnek

'a' -> C++: char
	   C: int

operátorok/kifejezések:
-----------------------
operátokrok
pl. == (egyenlőségvizsgálat)
	<
	++ (prefix, postfix)
	= (értékadás)
	+
	-
	::
	.
	->

kifejezés
x = 3 + y;
szintaxisfa, AST
	=
x		+
	3		y

van típusa (fordítási idejű)
van értéke (futási idejű)
lehet mellékhatása/side effect (futási idejű)

x + 7 Mi a típusa?
függ x típusától
7-nek látjuk a típusát -> int

bináris operátorok: ":)" operátor
a ":)" b -> típusa fögg a és b típusától
a és b típusa eltér

szokásos aritmetika konverzió:
1. ha az egyik típusa long double, akk a másik is long double-lé konvertálódik
2. kül, ha az egyik típusa double, akk a másik is double-lé konvertálódik
3. kül, ha az egyik operandus típusa float, akk másik is float-tá konvertálódik
4. kül, ha az egyik operandus típusa unsigned long int, akk a másik is unsigned long int-té konvertálódik
5. kül, ha az egyik operandus long int és a másik unsigned int 
	- long nem képes ábrázolni az összes unsigned int-et (sizeof(long) == sizeof(int)), akk mindkettő unsigned long int-té konvertálódik
	- kül unsigned int -> long-gá konvertálódik
6. kül, ha az egyik típusa long és a másik nem unsigned int, akk a másik long-gá konvertálódik
7. kül, ha az egyik típusa unsigned int, akk a másik is unsigned int-té konvertálódik
8. kül minden int-té konvertálódik
sizeof(int) <= sizeof(long)

unsigned int s = 6;
int x = -4;
if (x < s) // hamis

5L + 6.8 (long = double)
ˇdouble-lé

x = 3 + y + b * 2 + 5

	=
x		+
	3		+
		y		+
			*		5
		b		2

precedencia:
ne kezdjük el magolni, zárójelezzünk
x = 3+y+(b*2)+5

legmagasabb -> . ::
legalacsonyabb -> = ,

kötés:
x = 3 + a + b + 4; // balról kötés
x = (((3 + a) + b) + 4)

x = y = z = 6; // jobbról köt
x = (y = (z = 6))
			6
		6
mellékhatás: z 6 lesz


int i = 4;
i++; // |_ mellékhatás
++i; // |  uaz de az eredményük más

i = ;		//4
std::cout << i++;
// mellékhatás: i == 5
std::cout << ++i;
			//6


bool f()
{
	std::cout << 'f';
	return false;
}

bool g()
{
	std::cout <<'g';
	return true;
}

bool h()
{
	std::cout << 'h';
	return false;
}

if (f() == g() == h())
{
	std::cou << 'i';
}
else
{
	std::cout << 'h';
}
// output:
// fghi
// hfgi is lehet
// semmi sem biztosítja h ilyen sorrendben hívódjanak meg

C++: szekvenciapont
pl. ;
	= nem
	&&
	||
	,

if (a || b) // ha a igaz, akk b-t nem értékeli ki
if (a || f()) // akármilyen bonyolult fv-hívás, nem fogja kiértékelni
szekvenciapontnál nem garantál kiértékelési sorrendet (?)

int v[5];
for (int i = 0; i < 5; ++i)
{
	v[i] = i++; // nincs sorrendiség, nem tudjuk h a 2 oldal kiértékelése milyen sorrendhez van kötve
}