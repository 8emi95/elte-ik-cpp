2016.10.17.
6. C++ EA

// memory leak

Láthatóság, élettartam:

automatikus változók: (szabálya)
---------------------
- stack-en jönnek létre
- létrejönnek, amikor a vezérlés eléri a deklarációjukat
- megszűnnek, amikor a deklaráló blokk végét eléri a vezérlés

void f()
{
	int x;
	if (x == 0)
	{
		int y = 3; // konstruktora lefut
	} // destruktora lefut
}


dinamikus okbjektumok:
----------------------
- heap-en jönnek létre
- létrejönnek a new kiértékelésekor
- megszűnnek a delete kiértékelésekor

void f()
{
	int *p = new int(8); // nincs neve, heapen leallokált 1 int-nyi trterület
	// ...
	delete p;
}

heap: [8]
		^
stack: []
	   p

// egybefüggő tárterület kell de nem tudjuk hány elemnek
int i;
std::cin >> i;
int *v = new int[i];
// ...
delete []v;
delete []v; // futási idejű hiba: nem lehet 2x törölni uazt a tárterületet
// (1 newhoz 1 delete)

[ |    ]
---v----
   i


void g()
{
	int *p = new int(6); // leallokál egy tárterületet
	// visszavezetni automatikus változókra (?)
} // memóriaszivárgás (nincs törölve / felszabadítva a tárterület)

// ...
{
	lock l; // belső blokkban h az élettartama idáig tartson
}

void g()
{
	int *p = new int(6); //						}
	p = 0; // nullpointer						} memory leak még mindig
	delete p; // skip (em ad futási idehű hibát)}
}

globális/névtéribeli/osztálystatikus tag változók:
--------------------------------------------------
- statikus tárterületen jönnek létre
- létrejönnek a program indulásakor (gond(?))
- megszűnnek a program futásának végén
(static kulcsszó itt is)


lokális statikus változók:
--------------------------
- statikus tárterületen jönnek létre
- létrejönnek, amikor a vezérlés először eléri a definíciót
- megszűnnek a program futásának végén

void f()
{
	static int x;
	// meg lehet számolni h hányszor hívják meg f-et, mert túléli a fv-hívást
}


tömbelemek:
-----------
- létrejönnek a tartalmazó tömb létrejöttekor
- megszűnnek a tartalmazó tömb megszűnésekor

int v[5]; // fordítási időben látni a méretét, nem kell heap-en létrehozni
// 5 int létrejön, használható valid értékek
X v[6]; // X nevű osztály
// konstruktorhívással létre kell hozni az elemeket
// default konstruált elemeknek kell bent lenni
// nem tudja  compiler h mi a konstruktorparaméter úh biztosítani kell default constructort
// amikor a tömb megszűnik akk a tömbelemek is


osztály adattagok:
------------------
- létrejönnek a tartalmazó obejktum létrejöttekor
- megszűnnek a tartalmazó obejktum megszűnésekor

class X
{
private:
	complex c;
};

// létrehozás
X a; // le kell fusson a complex konstruktor
// a.c létezik, akkor is ha nem írtam konstruktort
// valódi, létező, működő, használható a objektum
// osztályadattagokat is megszűntetni...
// osztály adattagjai...
// steck-en létrehoz X-nyi tárterületet

// ha tömb lenne és nem lenne hozzá default constructro akk hiba h nem tudja létrehozni

X *p = new X(); // heap-en hozzuk létre az objektumot
delete p;


temporális objektumok:
----------------------
- létrejönnek a részkifejezés kiértékelésekor
- megszűnnek a teljes kifejezes kiértékelésének a végén (addig a memóriában kell tartani)

Matrix m, a, b, c, d;
// --
m = a + b + c+ d;
//  --v--
//temporális
//  ----v----
// temporális
// ------v-------
//   temporális

// részeredmények temporális kifejezésben tárolódnak
// bal- és jobbodlali operandusa van

template metaprogramming: exression template-eket lehet csinálni

for (...)
{
	for (...)
	{
		m[i][j] = a + b + c + d;
	}
}


// fv: felhasználónak kérdés, felh válaszol
char* question(const char* q)
{
	std::cout << q; // kiírjuk a kérdést
	char ans[80]; // válasznak létrehozunk egy tömböt (80-nál több karaktert ne gépeljen be)
	std::cin >> ans; // eltároljuk
	return ans; // visszaadjuk
	// memóriacímet kap, ide írhat a felhasználó, ha 80-nál többet ír akk elkezdhet adatokat felülírni
	// hackerek ezeket a hibákat szerették megtalálni
	// saját kódját....
	// pointer megmondja hol van, de itt már megszűnik az a tömb
	// 1. elemre mutató pointerré konvertálódik
} // nem jó


// globálissal
char and[80]; // globális változó túléli a fv-hívást, vissza tudjuk adni
// programfutás alatt végig elérhető bárhonnan -> NEM thread-safe
char* question(const char* q) // pointerként a válasz címe kell
{
	std::cout << q;
	std::cin.getline(ans, 80); // többit levágja
	return ans; 
}

std::cout << question("Hogy vagy?");
std::cout << question("Biztos?"); // nem tudjuk melyik fut le előbb de tfh az 1.
// 2.-ra igennel válaszol
// 2x kiírja h igen: felülírja a tárhelyet, ugyanazt a memóriacímet írjuk ki

[szarul\0]
[igen\0l\0] mindegy h marad-e vmi mert \0-val vége
pointeraritmetikával át lehet menni \0-n, vagy 80-elemű tömb x. elemét le lehet kérdezni
c strinreprezentáció szerint addig jelenik meg amíg el nem érem az első \0-t


// statikussal
char* question(const char* q)
{
	std::cout << q;
	static char and[80]; //			} láthatóság szempontjából jobb
	std::cin.getline(ans, 80); //	}
	return ans; //					} de ugyanúgy felülírja a utolsó válasz a többit
}


// dinamikussal
char* question(const char* q)
{
	std::cout << q;
	char* ans = new char[80]; // leallokál egy tárterületet
	std::cin.getline(ans, 80);
	return ans; // itt még nem veszítjük el h hol van leallokált tárterület (még nem memory leak)
} // memory leak lesz belőle (nem lehet felkészíteni az összes programozót h töröljön)


// ne mi hozzuk létre, nem kell leallokálnunk
char* question(const char* q, char* ans) // felhasználó, meghívó mondja meg hova
{ // mondja meg h ahol ezt leallokáltam hol van
	std::cout << q;
	static char and[80];
	std::cin.getline(ans, 80);
	return ans;
}

// adjunk vissza szabványkönyvtári string-et
std::string question(const char* q)
{ // std::string mögött heap-en allokált tárterület van
	std::cout << q;
	std::string ans;
	std::getline(std::cin, ans);
	return ans; // meghívodik a cop const és a heapen leallokált tárterületet le lehet másoltatni meghívó számára
} // memory problémákat felhasználói típusokra vezetjuk vissza
}