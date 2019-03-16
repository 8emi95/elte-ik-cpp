2016.10.12.
5. C++ GY


+/-: p pointeren keresztül s értékét megváltoztatni
int s = 5;
int *p = 0;

// válasz
p = &s;
*p = 7;

*********************************************************

F: általános karakterkonverzió.
M -> b
T -> K
f -> F

char conv(char ch);
		// ordó
- gyors, o(1) (konstans idejű)

char conv(char ch)
{										// 'M'. hely
	static const char c[] = {0, 1, 2, ..., 'b', 'N', 'O', ...}; // tömbelem-lekérdezés konstans idejű
	// pár soros script generálja le és bemásolja ide, vagy metaprogramot írunk
	return c[ch&0xff]; // &: bitenkénti és
					   // 0xff: 255
					   // x: valid tömbindex (legyen?)
											  //memóriában: &0...011111111
												//				  01101110 :ch
												//			 0...001101110 eleme [0,255]
												//		ugyanaz a bitsorozat
}

char - lehet előjeles
	 - lehet előjel nélküli

magas memóriaigény, nem karbantartható

- kevés memóriaigény

char conv(char ch)
{
	switch (ch)
	{
		case 'M': return 'b'; break;
		case 'T': return 'K'; break;
		case 'f': return 'F'; break;
		default: return ch;
	}
/*
	if ('M' == ch) // nem kell figyelni switchnél ==re
	{
		return 'b';
	}
	else if ('T' == ch)
	{
		//...
	}*/
}

karbantarthatóbb, mint a 255 elemű tömb
nem annyira karbantartható, mert:
szabályrendszer átírható anélkül h tudnám...
ha át kell írni akk a switch belsejében kell nyúlkálni


- karbantartható

két tömb:
from: 'M', 'T', 'f'
to: 'b', 'K', 'F'

char conv(char ch) // más fordítási egységben is lehetnek a paraméterek
{
	static const char from[] = {'M', 'T', 'f'};
	static const char to[] = {'b', 'F'}; // elemszám nem egyezik meg, nem tudni honnan tűnt el

	static const char from[] = {'M', 'T', 'f'};
	const int n = sizeof(from)/sizeof(from[0]); // előre kiszámoljuk a from tömb méretét, felhasználjuk to-ban tömbméretként
	static const char to[n] = {'b', 'K', 'F'};
	// DE!!!
	static const char from[] = {'T', 'f'}; // nem lehet to 3-elemű, fordítási hiba
	const int n = sizeof(from)/sizeof(from[0]);
	static const char to[n] = {'b', 'K', 'F'};

	static const char from[] = {'M', 'T', 'f'};
	const int n = sizeof(from)/sizeof(from[0]);
	static const char to[n] = {'b', 'F'}; // lefordul, 3-elemű tömböt lehet 2 elemmel inicializálni

	static const char from[] = {'M', 'T', 'f'};
	const int n = sizeof(from)/sizeof(from[0]);
	static const char to[] = {'b', 'F'};
	if (sizeof(from) != sizeof(to))
	{
		//
	}

	// linkerrel megkeressük from karakterét to-ban
	for (int i = 0; i < sizeof(from)/sizeof(from[0]); ++i)
	{
		if (from[i] = ch)
		{
			return to[i];
		}
	}
	return ch;
}

egy tömb karakterpárokkal:
struct Pair
{
	char from;
	char to;

	// static const Pair c[] = {{'M', 'b'}, {'K'} {'f', 'F'}}; // nem jó
	Pair(char f, char t) // konstruktor C++
	{
		from = f;
		to = t;
	}
};
char conv(char ch)
{
	static const Pair c[] = {{'M', 'b'}, {'T', 'K'} {'f', 'F'}};
	static const Pair c[] = {{'M', 'b'}, {'K'} {'f', 'F'}}; // nem jó

	static const Pair c[] = {Pair('M', 'b'), Pair('T', 'K'), Pair('f', 'F')};

	for (int i = 0; i < sizeof(from)/sizeof(from[0]); ++i)
	{
		if (c[i].from == ch)
		{
			return c[i].to;
		}
	}
	return ch;
}


***************************************************************

Pointerek:
----------

void*: típustalan pointeren

Pair p('s', 'y');
void* vp = &p; // rámutat egy Pairre
int s = 6;
vp = &s; // integerre mutat
// nincs pointeraritmetika


függvéypointer: olyan pointer, ami függvényre mutat

  n
szumma(a);
 i = 0

sum fv
n - paraméter
a - paraméter: fv-pointer; olyan fv-re mutat, ami intet vár paraméterként, double-lel tér vissza

double sum(int n, doble(*a)(int))
{
	double s = 0.;
	for (int i = 0; i <= n; ++i)
	{
		s += a(i);
	}
	return s;
} // lefordul


double f(int x)
{
	return 1./((x+1)*(x+1));
}
//...
std::cout << sum(12, f); // &f is lehetne de felesleges, mert mindenképp ez történik