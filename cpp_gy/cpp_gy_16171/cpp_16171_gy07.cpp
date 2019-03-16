2016.10.26.
7. C++ GY

-----------------------------------------------------------------
C++ Standard Template Library (STL):
-----------------------------------------------------------------
// sok kül implementációja van
// C++ szabvány áll mögötte, minden STL-könyvtár? C++ban ismerhető fogalom?
- konténer (adatszerkezetek), algoritmusok
http://www.sgi.com/tech/stl

*****************************************************************
F: eof-ig számokat olvasunk be, írjuk ki rendezetetten

vector: szabváy szerint garantálja C tömbökkel...
- egybefüggő tárterület
- push_back() végére rak: amortizált konstans idejű művelet
	- ha betelt akk vectro leallokál 2x akkor tárterületet, elején átmásolja az elemeket és felszabadítja a régi tárterületet (reallokáció)
nem minősül stl algoritmusnak.

#include <vector>
#include <algorithm> // std::sort(v.begin(), v.end()); 
#include <iostream>
#include <iterator>
void print(int);
int main()
{
	std::vector<int> v;			// }
	int i; // beolvasáshoz		// }
	while (std::cin >> i)		// } print
	{							// } std. inputon érkező intek intervalluma
		v.push_back(i);			// } iterátoros std::vector...
	}							// }

	std::vector<int> v (std::istream_iterator<int>(std::cin), // std::cin.begin()
						std::istream_iterator<int>()); // sd::cin.end()
	// v vector, 2 istream_iterator névtelen objektum

	std::sort(v.begin(), v.end()); // átlagosan n*logn műveletegénnyel kell rendelkeznie
	//			[) intervallum

	for (i = 0; i < v.size(); ++i)	// }
	{								// } szabványkönytári megoldásokra vezessük vissza (?)
		std::cout << v[i] << ' ';	// } std::for_each(v.begin(), v.end(), print) -> szabványkönyvtári hívás
	}								// }
	// helyette még lehetne:
	for (std::vector<int>::iterator it = v.begin(); it = v.end(); ++it)
	{
		std::cout << *it <<' ';
	}

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}

void print(int s)
{
	std::cout << s << ' ';
}


// végleges main
int main()
{
	std::vector<int> v (std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
	std::sort(v.begin(), v.end());
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}

****

#include <iterator>
std::vector<int> v (std::istream_iterator<int>(std::cin), // std::cin.begin()
					std::istream_iterator<int>()); // sd::cin.end()
iterátor: ...

// ...
int x[] = {8, 2, 6, 3};
std::sort(x, x + h);

[8][2][6][3]
^n?			^n+4?
 h?


#include <vector> ->
for (std::vector<int>::iterator it = v.begin(); it = v.end(); ++it)
{
	std::cout << *it <<' ';
}
// helyette:
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
																// kiírás utáni elválasztó




// multisetben megoldva
// multiset, set: rendezettségen alapuló rendezés
// multiset: többször lehet vmi
// set: halmaz, vagy van benne v nincs
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
	std::multiset<int> m(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
}

*****************************************************************
F: betűstatisztika
almafa
(eof)
a: 3
f: 1
l: 1
m: 1
logaritmukus időben meghatározható h hányszor szerepel vmi multisetben.

#include <set>
#include <iterator>
#include <iostream>

int main()
{
	std::multiset<char> stat(std::istream_iterator<char>(std::cin), std::istream_iterator<char>());
	for (std::multiset<char>::iterator i = stat.begin(); i != stat.end();)
	{						// ++ v. --		log-ns
		std::cou << *i << ":" << stat.count(*i) << std::endl;
		i = stat.upper_bound(*i);
		//  ---------|----------
		//		log-ns ?
	}
}

std::begin()			std::end()
->	a a a f l m 	<-
	[	) <- equal_range('a')
	) -> upper_bound('a')
	[ -> lower_bound('a')
		  [)
		     [)


#include <map> // kulcs-érték párokat tartalmaz
#include <algorithm>
#include <iostream>

void print(const std::pair<char> &p);
{
	std::cout << p.first << ": " << p.second << std::endl;
}

int main()
{		// típus - char, érték - int
	std::map<char, int> stat;
	char ch;
	while (std::cin >> ch)
	{
		++stat[ch]; // log-ns (nem konstans idejű mint tömböknél), nincs indexelés
	}
	std::for_each(stat.begin(), stat.end(), print); // &print lesz, print() fordítási hiba
}