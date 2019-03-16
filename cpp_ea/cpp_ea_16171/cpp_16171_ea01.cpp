2016.09.12.
1. C++ EA

10:15-
patakino@elte.hu
patakino@web.elte.hu/pny2 - vizsgafeladatok

gy: 3 db +/-, kód kipróbálása
v: elmélet - 15 kérdéses teszt (EA-n többnyira, GY is)
   gyakorlat - 3 óra
bead: opcionális

ajánlott irodalom: Bjarne Stroustrup - A C++ Programozási nyelv
				   Scott Meyers - Hatékony C++

tematika: nyelvi eszközök (?)				(c++ magas, proc alacsony szintű)


----------------------------------------
Nyelvek története, csoportosítás:
----------------------------------------

// gépi kódban csak számok, CPU ezt érti		// szöveges azonosító gépi kódhoz
1945: alacsony szintű - gépi kód (CPU) <--> assembly, imperatív programozás


programozási paradigma: (strukturált/logikai/objektumorientált/stb programozás)
-----------------------
absztrakció...
szemléletmódot ad...
programozási tételek

1950s: magas szintű - vezérlési szerkezetek
					- változók

1970: procedurális nyelvek - C, Pascal
						   - strukturált nyelvek (vezérlési szerkezetek csökkenetése)

1967: Simula67 - 1. objektumorientált nyelv

1980: C++ - C objektumorientált...
		  - szabványosítás...
		  - minden leforduló C kód C++ kód is legyen (ma már nem igaz)
		  - C hatékonyságainak megőrzése

1966: LISP - 1. funkcionális nyelv (matematikai fv-t értékel ki, vezérlésről/végrehajtásról nem beszél) // a program végrehajtást ír le
		   - Haskell, Clean, Erlang

1970: logikai programozás - Prolong
						  - program = tények leírása + állítás
						  - állítás következménye-e a tényeknek <- programfutás
						  - rezolúciós algoritmus fut le

1970s: dekleratív programozás - SQL
							  - deklarálom h mit szeretnék elérni, milyen adat kell
							  - SELECT * FROM users WHERE id like 'x%'
							  - osztályhierarchia
							  - osztályok, öröklődés, altípusok

C++: multiparadigmás = nem kötődik egy paradigmához sem direktben, többet is támogat


generatív technológiák:
-----------------------
vmi generálja a kódot, módosítja bizonyos részeit
- generikus programozás: C++ STL (Standard Template Library)
						 konténerek ----> algoritmusok
						 	....	<----	....
						 			^  ˇ  ^				//nyilak keresztbe
						 nem kell belenyúlni könyvtár...
- template programozás: compiler fordítás közben ellenőriz, stb
- aspektusorientált programozás: néhány kód mindegyik osztálynál megjelenik
								 logolással foglalkozó kódrészlet mindenhol megjelenik
								 aspektusszövő kiszervezi... rászövi az alapkódra