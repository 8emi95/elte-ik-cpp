2016.11.21.
10. C++ EA

---------------------------------------------------
Sablonok (tamplate-ek):
---------------------------------------------------

típussal trténő paraméterezés
C-ben nem látezett ez a fogalom

int printf(char *format, ...);
void* mallac(int bytes); // memóriát allokál le, megkapja hány bájtot kell allokálni
void free(void* ptr); // memóriát szaadít fel
// void*: elvesztem azt az infót h mi van ott, cserébe kül típusokkal dolgozhat... (?)

// makró
#define MAX(a, b) ((a)<(b) ? (b) : (a))

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

template<class T>
void swap(T &a, T &b)
{
	T tmp = a; //copy ctor
	a = b; // értékadás
	b = tmp; // értékadás
}

double x = 1.36;
double y = 2.4;
swap(x, y); // paraméter dedukció
// T ekviv double
// példányosítás

swap(std::cout, std::cerr); // standard output-ot és standard errort cseréljük fel
// fordítási hiba


std::list<int> c; // <int> egy template
std::sort(c.begin(), c.end());
// fordítási hiba (operator< és operator= a gond)

hiba:
kétirányú láncolt lista
-> [] <-> [] <-> []
nem lehet ugrálni az elemek között, csak előzőről következőre
sort meg akarja nézni h melyik van előrébb

template<class Container>
void f(const Container &c)
{
	int i = c.siye();
}

f(std::list<int>()); // ford. hiba


template paraméter: fordítás idejű paraméterek
- típusparaméter
- integrális konstans (pl. int, char, bool)
- pointerek (pl. fvpointer, tagfv pointer)

template<int N>
void x(int (&x)[N]) {...}

template<class T, int N>
clss Array
{
	T v[N];
}

Array<int, 8> a; // fordítási időben ismert paraméter, kell h ismerje a compiler
Array<int, 4+4> b = a; // ok
Array<int, 9> c = a; // ford hiba, a és c típusa eltér


specializáció:
--------------
std::vector<int> v;
int *p = &v[0]; // lefordul
		// int&
// bool-ként integert használtak régebben, de 32x annyi memória

std::vector<bool> c;
// NEM bool&
// c[0] = true;
bool *q = &c[0]; // ford hiba


osztálytemplate-ek specializációi:
----------------------------------
template<class T>
class Matrix<T*> {...};

template<>
class Matrix<bool> {...};

template<typename T> // int lehet templatepm
class Matrix {...};

STL-ben: set, multiset, ... alapért növekvő rendezés

template<class Key,
		 class Comp = std::less<Key, // bináris predikátumfunktor?
		 ...>
class set;


std::list<int> c;
std::sort(c.begin(), c.end()); // ford hiba
c.sort(); // tagfv
// lusta példányosítás / lazy instantiation
class complex {...}; // nem rendezhető


std::list<complex> c;
c.push_back(complex(1.2, 6.8)); // lefordul
//...
c.sort(); // ford hiba
std::set<complex> d; // lefordul
d.insert(complex(1.2, 4.4)); // ford hiba