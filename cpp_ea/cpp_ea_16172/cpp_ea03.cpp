2017.03.01.
3. CPP EA

compiler
nyelvi fordítás:

tokenizál:
----------

int main()
{
	std::cout << "Hello World" << std::cout;
	return 0; // -> ?
}

- kulcsszavak: return, int
- azonosítók: std, cout
- konstansok: 0
- konstans szövegliterál: "Hello World"
- operátorok: ::, <<
- szeparátorok: {, ;, }

x = y + 3 -> kifejezés


kulcsszavak: const, static, int, if, while, stb.
------------


azonosítók:
-----------
- betűvel kezdődik (_ underscore = betű)
- betűvel/számmal folytatódhat
- kulcsszavak kizárva (nem változhat meg a jelentésük)
- legális: __xy, abc666, ABC666 (nem uaz), ConsT
(case senstive nyelv:)
- nem legális: 666abc
- többszavasak: push_back (C++), CamelCase (Java)
- névkonvenciók:
	- logika az azonosítókban
	- Hungarian notation: 
		- típusinfók: lpzstrMsg -> '\0'-ra végződő string legelső karakterére mutató 32 bites pointer
	- NULL -> preprocesszor szimbólum
nm a.out

class complex
{
	double _re, _im;
public:
	complex(double re, double im)
	{
		_re = re;
		_im = im;
	}
}

C++ szabvénykönyvtár: (halmaz)
rendezett adatszerkezet: set, multiset, map, multimap
jellemző: piros-fekete ga
__rb_tree...
_RB_tree...


konstans szövegliterálok:
-------------------------

- típus
- érték

"Hello"
['H']['e']['l']['l']['o']['\0'] // -> \0 karaktert kell nézni, string vége
^
p

C: char[6]
C++: const char[6]

void f()
{
	// C
	char *p = "Hello";
	int len = strlen(p);

	// C++
	char *p = "Szia"; // warning
	// konstansoknak fenntartott tárterület
	p[1] = 't'; // lefordul, futási időban oprendszer leállítja a programunkat
}

int strlen(char *str) { }

Pascal: a tömb legelső byte-ján van leírva h milyen hosszú a string
Java: java.lang.String immutable, StringBuilder és StringBuffer -> mutable


konstansok: nincsenek feltétleül a memóriában
-----------
- típus
- érték

8 -> érték: 8
	 típus: int (bitsorozat)
int: előjeles egész típus, előjelbit

hány bites egy int? sizeof(int) <= sizeof(long) // long int
akkora legyen ami jól kezelhető (optimális) a proci szempontjából?
16 bites CPU: max ábrázolható int -> 32767
int x;
20000 + x // 20000 ne int legyen
20000L: long típusú konstans
