2017.03.29.
6. CPP GY

1. pót +/-:
int f(int* p, int s)
{
	int x = 0;
	for (int i = 0; i < s; ++i)
	{
		x += *p;
		++p;
	}
}
meghívni úgy h lefordul és nem okoz futási idejű hibát!


-------------------------------------------------------------
Referenciák C++-ban:
-------------------------------------------------------------

int s = 2;
int *p = &s; // & s itt címképzés
*p = 6;
std::cout << s; // 6
int &r = s; // r: referencia, álnév, mindig ugyanannak az álneve
r = 4;
std::cout << s; // 4


// s, r, c (s és r megkülönböztethetetlenek)
// [2] -> [6] -> [4] -> [2] [2]
// ^p					^p

int k = 2;
r = k;
const int &c = s; // c-n keresztül ne mváltoztathatjuk meg s értékét
const int &five = 5;


/* C-s inkrementáló fv */
void inc(int* p)
{
	(*p)++;
}
int x = 3;
inc(&x);
inc(0); // elszáll mert nullpointert dereferálok


// C++
void inc(int& r)
{
	++r;
}
int s = 4;
inc(s);


Pointer (C/C++):									Referencia (C++):
- memóriacím (futási idejű értéke)					- álnév
- dereferálás/címképzés								- [-]
- változhat h hova mutat							- mindig ugyanannak az álneve
- nullpointer										- [-]
- [-]												- kötelező inicializálni
- pointer-aritmetika								- [-]
- függvénypointer									- [-]


void fv(int s) // s: formális pm
{
	// ...
}
fv(6); 	// 6: aktuális pm
		// int s = 6
		// formális pm = aktuális pm



void f(int i);
void g(int& r);
void h(const int& c);

// ˇmelyik fordul le?
int s = 2;
f(s); // lefordul
f(4); // lefordul
// s == 2 
f(s + 5); // lefordul
f(s++); // lefordul
f(++s); // lefordul
// f: új lokális változó jön létre (i), belemásolódik az aktuális pm
// költség: másolási/felszabasítási

void fx(std::std::vector<int> v) {}

int x = 3;
g(x); // lefordul
// x értéke megváltozhat ezen a ponton: g az x-szel dolgozik r álnéven keresztül
g(5); // fordítási hiba
g(x + 2); // fordítási hiba
g(x++); // fordítási hiba
g(++x); // lefordul, ugyanazt az x-et adja át mint g(x), csak előtte megnöveli 1-gyel
// nincs másolási/felszabasítási költség

int i = 5;
h(i); // lefordul
// i értéke 5 marad
h(4); // lefordul
h(i + 3); // lefordul
h(i++); // lefordul
h(++i); // lefordul
// const int& c: h fv-n belül nem szabad c-t változtatni
// nincs másolási/felszabasítási költség (h fv-t i-vel delegük?)


F: standard input-ról int-eket olvasunk be eof-ig, írjuk ki rendezetten
bináris fa:
		6 (root) <- node
	2		8
	  5		  12
5: root -> left -> right -> val
*(*((*root).left).right).val

struct Node
{
	int val;
	Node *left, *right;
	Node(int c)
	{
		val = v;
		left = right = 0;
	}
};
void print(const Node *n)
{
	if (n)
	{
		print(n -> left); // (*n).left
		std::cout << n -> val << ' ';
		print(n -> right);
	}
}
void insert(Node *n, int v) // *&n -> jól működik
// C-ben: Node **n + címképzések néhol, nehezen átlátható
{
	if (n)
	{
		insert(v <= n -> val ? n -> left : n -> right, v);
	}
}
else
{
	n = new Node(v); // fel kell szabadítani a leallokált memóriát
}
/*
		6 (root)
	2		9
			  10
*/
int main()
{
	Node *root = 0;
	int i;
	while (std::cout << i)
	{
		insert(root, i);
	}
	print(root);
	dealloc(root);
}
/*
6 2 5 7 1
(eof) // nem ír ki semmit (se fordítási, se futási idejű hiba)
*/
void dealloc(Node *n)
{
	if (n)
	{
		dealloc(n -> left);
		dealloc(n -> right);
		delete n;
	}
}