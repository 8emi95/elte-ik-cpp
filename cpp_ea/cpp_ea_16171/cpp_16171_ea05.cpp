2016.10.10.
5. C++ EA

int i = 0;
v[i] = i++; // nem garantál sorrendet
f(i++, ++i); // 2 pm-es fv
// nem egyértelmmű, mellékhatásos kifejezésekkel szokott gond lenni
// itt nem szekvenciapont a vessző

szekvenciapont:
;
||
&&
, (operátor)

int x;
while (std::cout >> x,x) // x! = 0
{ // sorrendiséget garantál: beolvasás megtörténik, kiértékeljük az x-et, kifejezés eredménye x jobboldali operandus
	//...
}

f((i++,i++)) // egy paraméteres fv
		v
		eredmény



------------------------------------------------
Láthatóság, élettartam:
------------------------------------------------

láthatóság: fordítási idejű ellenőrzés, 1-1 azonosító a kód mely részéről mit azonosító
-----------

// így ne programozzunk C++-ban (valid tho):
a.cpp:
int x; // globális változó: ne róbáljuk használni
static int y; // static: más fordítási egységből nem hivatkozható (anonim namespace)
extern int s; // szükséges
// másik fordítási egységben (s.cpp) létrehozott váltózó, de innen is használjuk
namespace // anonim névtér
{
	int k;
}
void f()
{
	// még egy x-et létrehozni itt nem szabályos
	int x = y; // static int y;
	x = s; // extern int s;
	s = k; // anonim namespace-ben int k;
	++x; // f--ben int x = y
	::x = y; // int x; (globális x-et így érjük el)
}
namespace ns
{
	int x; // ns::x
	void f(); // ns::f()
	// külső f-fel nem ütközik
}
void ns::f()
{
	x = y; // ns-beli x, globális static y
}
void g()
{
	++x; // globális x
	int x = 3;
	if (y == x) // x az előző lokális x-re hivatkozik, globális y
	{ // globális x elfedi lokális x-et?
		int x = s; // globális s
		++x; // előző, legbelső x-et oldja fel
		::x; // globális x
		// x = 3-at nem lehet hivatkozni itt, elfedte
	}
	++x; // int x = 3;
}


s.cpp:
int s; 

****

élettartam: futás közben milyen változók mikor jönnek létre, szűnnek meg
-----------

- automatikus változók
- dinamikus objektumok
- globális/névtér/osztálystatikus tag (osztályszintű statikus: log file vektorba log-olja h mi történik)
- lokális statikusok
- osztály adattag
- tömbelemek
- temporáris objektumok

memóriakezelés:
- végrehajtási verem / runtime stack: alprogramok globális váltózói
- heap memória: OS-szintű megoldás, C++ szerint a programozó feladata ennek a kezelése
- statikus tárterület

memory leak: Javaban

aktivációs rakord / stack frame, fv-hez kapcsolható
fv paraméterei, lokális válozói, adminisztratív infók


változó/objektum:
- mikor jön létre: mely ponttól kezdve valid/használhaó a változó/objektum
- mikor szűnik meg
- miylen memóriaterületen/-részen lesz

void f()
{
	int i = 3;
	int x = 5;
	if (x == ...)
	{
		++i;
		int y = x;
	}
}

void f()
{						   //f ();
	int s;			//   8
	std::cout << s; // <---> f();
	s = 8;
}