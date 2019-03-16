2016.10.19.
6. C++ GY

+/- pótlás:
const int *p = 0;
int *const q = 0;
Mi p és q típus között a különbség?

-------------------------------------------
Referenciák C++-ban: (C-ben nem volt)
-------------------------------------------

int i = 2;		// i
int *p = &i;	// [5]
*p = 5;			// ^p

int&r = i;  // r: álnév, referencia
			//	  mindig ugyanannak az álneve
r = 8;			// i, r
int j = 1;		// [1]
r = j;			// ^p

const int&cr = r;	// konstans referencia
					// a cr ??? arcsi't'an ??? keresztül a hivatkozott tárterület nem módosítható
++cd; // fordítási hiba
// i, r, cr
// [1]
// ^p
const int\hat = 6; // OIL pipa????

pointer = memóriacím:
- címképzés/dereferálás
- pointer változhat h hova mutat
- nullpointer (épp nem mutat semmilyen valid tárterületre)
- nem kötelező inicializálni
- pointer-aritmetika (lehet léptetni összefüggő tárterületen ???)
- fv-pointer

referencia = álnév:
- nincs dereferálás
- minidg ugyanannak az álneve
- nincs nullreferencia
- kötelező inicializálni
- nincs aritmetika ???
- nincs fv-referencia


F: integer változó inkrementálása
/* C */
void inc(int *p) // nullpointernél elszáll
{
	++(*p); // pointer által mutatott tárterület növelése
}
int s = 4;
inc(&s); // memóriacím

// C++
void inc(int &r)
{
	++r;
}
int x = 3;
inc(x);


fv-ek paraméterezését jól leírja a kövi konstrukció:
	// formális paraméter
void fv(int s)
{	//				^
	//			formális pm = akt pm
}	//				v
fv(5); // aktuális paraméter



void f(int i); // érték szerinti paraméterátadás
void g(int &r);
void h(const int &x);
-------------------------------------------------

int a = 4;
f(a); // lefordul, a értéke 4 marad
f(a + 2); // lefordul
f(3); // lefordul
f(a++); // lefordul
f(++a); // lefordul
f meghívásakor létrejön egy új lokális változó (i)
ebbe bemásolódik az aktuális pm értéke.
a fv a lokális változóval dolgozik.
futási idő: másolási/felszabadítási költség - ezt szeretnénk csökkenteni, ezért hozták be a referenciákat

void skip(std::vector<int> v) {} // üres törzsű, de 2x is szól OS-nek
// vektor: felhasználói típus


int x = 2;
g(x); // lefodul, x értéke megváltozhat
g(x + 3); // fordítási idejű hiba (r álnéven keresztül megváltoztatni az értékét nincs értelme)
g(4); // fordítási idejű hiba
g(x++); // fordítási idejű hiba
g(++x); // lefordul
g x-szel dolgozik álnéven (r) keresztül
nincs másolási/felszabadítási költség


int y = 3;
h(y); // lefordul, y 3 marad, nem engedi x értékét megváltoztatni
h(y + 3); // lefordul, 6 amikro xre hivatkozunk
h(4); // lefordul, 4
h(y++); // lefordul, y 4
h(++y); // lefordul, y 5 lesz, visszadja, x belül 5, y is 5
nincs másolási/felszabadítási költség
h álnéven keresztül meglévő adattal dolgozik.


F: standard inputról eof-ig egészeket (int) olvasunk be, írjuk ki rendezetten!
nem tudjuk hány szám lesz
nem akarjuk/tudjuk megkérdezni mennyi lesz
bináris fa, keresőfa

class Node
{
public:
	int val; // value
	Node *left, *right; // * az azonosítóhoz köt
	Node(int i)
	{
		val = i;
		left = right = 0;
	}
};

void print(const Node *n)
{
	if (n)
	{
		print(n -> left); // (*n).left, esszük n által mutatott objektumot és annak a left tagját
		std::cout << n -> val << " ";
		print(n -> right);
	}
}
//			Node *&n: így működik rendesen
void insert(Node *n, int v) // v beszúrandó érték
{
	if (n) // ha n igaz akk n nem nullpointer
	{
		insert(v <= n -> val ? n -> left : n -> right, v);
	}
	else
	{
		n = new Node(v);
	}
}

int main()
{
	int i;
	Node *root = 0;
	while (std::cin >> i)
	{
		insert(root, i); // root itt nullpointer marad, érték szerint lemásolódott
	}
	print(root);
}

> 6
  2
  5
  8
  (eof)
>
se fordítási se futási idejű hibát nem kapunk, de látszólag semmit sem ír ki

void insert(Node *&n, int v) !!!
C-ben: Node **n
// root alatti vmelyik részfára mutató pointer lesz (?)

void f(int i) { ++i; }
int s = 2;
f(s); // s 2 marad


mainben insertet meghívjuk:
Node *n = root // root nullpointer
n nullpointer lesz // root és n különböző, ebben a időpillanatban megegyezi kaz értékük

void g(int *p) { p = 0; }
int x = 2; // p megadja h hova mutat az x
f(&x);
// x
// []
// p:0
x ugyanaz marad, van p nevű másolata, f-ben nem látom x-et...


HF: new-val allokált tárterület nincs felszbadíta, memory leak
	kell egy fv amivel felszabadítjuk, printhez hasonló csak postorder bejárás (bal, jobb részről bejárás, ...)