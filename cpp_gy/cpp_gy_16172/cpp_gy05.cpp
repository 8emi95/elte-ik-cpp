2017.03.22.
5. CPP GY

--------------------------------------
tetszőleges karakterkonverzió:
--------------------------------------
B -> m
T -> A
H -> h

char conv(char ch);
- gyors (o(1))
- kevés memóriaigény
- karbantartható

gyors:
------
ch:   11011100
&0...011111111 (összeéseljük)
+0...011011100 (same)
char: lehet előjeles és előjel nélküli

char conv(char ch)
{
	static const char cnv[] = {0,1 2, ..., 'A', 'm', 'C', ...};
	return cnv[ch&0xff]; // -> int eleme[0, 255]
	// 0xff: szám (255) -> int
	// &: bitenkénti és
}

A -> A, C -> C is benne van (redundáns adatok)

kevés memória:
--------------

char conv(char ch)
{
	switch(ch)
	{
		case 'B': return 'm'; break;
		case 'T': return 'A'; break;
		case 'H': return 'h'; break;
		default: return ch; break;
	}

/*	if ('B' == ch)
	{
		return 'm';
	}
	if ('T' == ch) // többször lesz leírva a feltétel
	{
		return 'A';
	}*/
}

macerás átírni, tudni kell h van feldolgozva.

karbantartható:
---------------
2 tömb - from, to

char conv(char ch)
{
	static const char from[] = {'B', 'T', 'H'}; // }
	const int n = sizeof(from)/sizeof(from[0]);	// } nem muszáj itt lennie (ebben a fájlban)
	static const char to[n] = {'m', 'F', 'h'};	// }
	for (int i = 0; i < sizeof(from)/sizeof(from[0]); ++i)
	{
		if (from[i] == ch)
		{
			return to[i];
		}
	}
	return ch;
}

static const char from[] = {'B', 'H'};
const int n = sizeof(from)/sizeof(from[0]);
static const char to[n] = {'m', 'F', 'h'}; // fordítási hiba

static const char from[] = {'B', 'T', 'H'};
const int n = sizeof(from)/sizeof(from[0]);
static const char to[n] = {'F', 'h'}; // lefordul

static const char from[] = {'B', 'T', 'H'};
const int n = sizeof(from)/sizeof(from[0]);
static const char to[n] = {'m', 'F', 'h'};
if (sizeof(from) != sizeof(to)) {...}
C++11: static_assert


1 tömb - karakterpárok

struct Pair // C kód szerint
{
	char from;
	char to;
	Pair(char f, char t) // C++
	{
		from = f;
		to = t;
	}
};
char conv(char ch)
{
	// static const Pair cnv[] = {{'B', 'm'}, {'T', 'F'}, {'H', 'h'}};
	static const Pair cnv[] = {Pair('B', 'm'), Pair('T', 'F'), Pair('H', 'h')};
	for (int i = 0; i < sizeof(conv)/sizeof(conv[0]); ++i)
	{
		if (conv[i].from == ch)
		{
			return conv[i].to;
		}
	}
	return ch;
}



--------------------------------------------------
pointerek: fv-pointerek (C-ben is volt)
--------------------------------------------------

szumma_i=0..n(a); sorozat:paraméter (sum fv)
N (int) -> R (double)

double (*sorozat) (int);
double: visszatérési érték típusa
(*sorozat): fv.ptr neve
(int): fv paramétereinek a listája

double sum(int n, double (*a) (int))
{
	double ret = 0.0;
	for (int i = 0; i <= n ; ++i)
	{
		ret += a(i);
	}
	return ret;
} // lefordul
double rec(int x)
{
	return 1./(x + 1);
}
double f(int s)
{
	return s/10.;
}

std::couz << sum(10, rec); // &rec
std::cout << sum(4, f); // &f