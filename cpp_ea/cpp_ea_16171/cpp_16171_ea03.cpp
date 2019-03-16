2016.09.26.
3. C++ EA

Fodítóprogram
-------------
tokenekre bont: tetszőleges whitespace határolhatja őket, tokeneken belül nem
- kulcsszavak:	értelme sose változik meg
				if, while, int, auto, const, virtual
- azonosítók:	- nem kezdődhet számmal
				- betűvel kezdődik (_: betű)
				- betűkkel, számokkal folytatódhat
				- nem lehet kulcsszó
				- case-sensitive ("If" lehet változónév, "If" != "iF", "_if" valid *dont use it tho*)
				- angol azonosítók használatára törekedni (ne fele magyar, fele angol)
				- push_back()  _   _
				- camel case  | |_| |_
				- hungarian notation: az azonosítóba tíus- és egyéb infókat kódolunk, mostanában nem népszerű
				  bF?und (boolean)
				  lpzstrMsg (lp - long pointer, zstr - zero terminated string)
				- _-sal kezdődő azonosítók szabálya:
					c++ szabványkönyvtárában rendezett adatszerekezetek (forráskódja), amiket nem tudnak előre lefordítani
					pl. set, multiset, map, multimap
					logaritmikus műveletigény
					háttérben rendezett adatszerekezet, amiől nem tudunk túl sokat
					bizonyos eseteket nem tud a szabvány megadni
					__rb.tree... -> red-black tree keresőfa működésével egyezik meg
					fenntartottak a compilernek belső implementációs célokra
					névütközési problémák lehetnek
- konstansok:	- van típusa
				- van értéke
				  36 -> típus: int, érték: 36
				  int: bitsorozat, műveletek (definiálják h bitsorozattal milyen műveletek értelmesek)
					   előjeles egészek ábrázolásása
					   alapértelmezett számábrázolás
					   legyen optimális
					   sizeof(int) implementációfüggő

					   16 bites gép:
					   legnagyobb ábrázolható int 2^15-1 (15 - egyet előjelbitnek kell hagyni)
					   [-32768, 32767]

int x = 20000;
...
x+20000; //túlcsordul
//int-összeadás
x+20000L; //típusa: long
//long-összeadás
58U; //típusa: unsigned int
17UL; //típusa: unsingned long
036; //típus: int
	 //értéke: 30
	 //0: oktális (8-as) számrendszer
0x36; //0x: hexadecimális (16-os) számrendszer
	  //értéke: 54
0xbL; //11, long

				  long int / long: 
				  sizeof(short) <= sizeof(int) <= sizeof(long)
				  intre nem mondja meg hány bájt, csak h előjeles és van kisebb short + nagyobb long

				  unsingned: lemondunk az előjelbitről [0.65535]?
				  unsinged int: előjel nélküli számábrázolás (Javában minden előjeles)

				- nem kötelező benne lenniük a memóriában
- konstans szövegliterálok:	- van típusa
								const char s[6] = "Hello";
								'H', 'e', 'l', 'l', 'o', '\0'
								s[0]					 s[5]
														 kerülhet előrébb is, rövidebb stringgel dolgozunk
								const kulcsszó eredetileg nem volt C-ben
								
								char *p = "Hello"; (fv-en belüli lokális változónév)
								p = pointer: - memóriacímre mutat futás közben
											 - hol kezdődik a szöveg a memóriában
											 - az első \0-ig fog tartani
								backward compatibility: c kódok lefordulnak c++-ban
								depreceted conversion: több karakter akk nem bootol a gép? benne kell lenniük a meóriában?

								Pascal: első byte-on jelzi a string hosszát
								Java: java.lang String - immutable típus (nem megváltozatatható, ha megváltoztatom *új karaktert hozzáadva* akk létrejön egy új string obj, több szálról könnyebben kezelhető)
									  Stringbuilder/StringBuffer - mutable
									                  ťhread-safe
							- van értéke
- operátorok
- szeparátorok

#include <iostream>
int main()										//int - kulcsszó
												//main, std, cout - azonosító
{												//"Hello World!" - konstans szövegliterál
	std::cout << "Hello World!" << std::endl;	//; - szeparátor
	return 0; //elhagyható						//::, << - operátor
												//return - kulcsszó
												//0 - konstans
}