2017.03.22.
5. CPP EA

---------------------------------------
láthatóság, élettartam:
---------------------------------------

a.cpp:
int x; // globális
static int y;
extern int k;
namespace // anonim, névtelen
{
	int s; // ::s
}
namespace A
{
	int x; // A::x
	void f(); // A::f()
}
void f()
{
	++x;
	int x = y;
	if (k == 0)
	{
		int x = s;
		++x;
	}
	++x;
}
void A::f()
{
	++x;
	++y;
	int x = s;
	y =:: x;
}

b.cpp:
extern int x;
// y, s nem érhető el innen

c.cpp:
extern int x;
// y, s nem érhető el innen


élettartam: Mikor fut le a konsi?
-----------
- változók:
	- mikor jönnek létre?	// }
	- mikor szűnnek meg?	// } mikor használató validan a változó?
	- ... dekonsi?	// }
- milyen...
	-végrehajtási verem (runtime stack)
	- heap
	- statikus tárterület


végrehajtási verem:
- lokális változók


				//			[                        ]
stack frame		// { sp ->  [adm infó                ] f()
aktivációs		// {		[fv parancs + visszatérés]
rekord			// { sp ->  [fv | lok | vált         ] <- mur?

stack-overflow
végtelen rekurzió:
int fac(int n)
{
	return n*fac(n-1);
}

heap:
ha az adatok mérete fordítási időben nem ismert, akkor dinamikusan allokálódnak
c/c++ programo feladata ennek felszabasítása


void f()
{
	int i;
	std:cou << i;
	i = 423;
}
int main()
{
	f();
	f();
}


garbage collector.
valgrind?
C++: resource-oriented
RAII?


- automatikus változók
- dinamikus változók
- lokális statikusok
- globális/névérbeli/osztály statikus tag
- osztály adattagok
- tömbelemek
- temporális obj-ok

automatikus változók:
---------------------
- létrejönnek, amikor a vezérlés eléri a deklarációt
- megszánnek, amikor a deklaráló blokkot elhagyja a vezérlés
- stacken jönnek létre

void f(int i)
{
	int x = 1;
	if (x == i)
	{
		++x;
		std::vector<int> y(i);
	}
	++x;
}

dinamikus változók:
-------------------
- heapen jönnek létre

int k;
std::cin >> k;
int *p = new int[k];
delete []p;

int *q = new int(k);
delete q;