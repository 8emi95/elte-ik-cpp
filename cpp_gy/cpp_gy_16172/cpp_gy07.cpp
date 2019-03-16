2017.04.05.
7. CPP GY

--------------------------------------------------------
C++ Standard Template Library (STL):
--------------------------------------------------------
- konténer	adatszerk (vector, list, set, map, ...)
- algoritmusok (vount, for_each, copy): konténerfüggetlen

// http://www.sgi.com/tech/stl

- aszimptotikus műveletigény garanciák


F: eof-ig int-eket olvasunk be, írjuk ki rendezetten!

#include <vector>
#include <algorithm>
#include <iostream>
int main()
{
/*	std::vector<int> v;
	int i;
	while (std::cin >> i)
	{
		v.push_back(i); // amortizált konstans idő
	}*/
	std::vector<int> v(std::istream_iterator<int>(std::cin), std::istream_iterator<int>()); // same as above

	std::sort(v.begin(), v.end());

/*	for (i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << ' ';
	}*/
	// std::for_each(v.begin(), v.end(), print); // same as for loop above
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
}
void print(const int &i)
{
	std::cout << i << ' ';
}


#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
int main()
{
	std::multiset<int> m(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
	std::copy(m.begin(), m.end(), std::ostream_iterator<int>(std::cout, " "));
}



F: betűstat
almafa
(eof)
a: 3
f: 1
l: 1
m: 1


#include <set>
#include <iterator>
#include <iostream>
int manin()
{
	std::multiset<char> stat(std::istream_iterator<char>(std::cin), std::istream_iterator<char>());
	for (std::multiset<char>::iterator it = stat.begin(); it != stat.end();)
	{
		std::cout << *it << ":" << stat.count(*it) << std::endl;
		it = stat.upper.bound(*it); // ˇlag-cs ???
	}
}


#include <map>
#include <algorithm>
#include <iostream>
void print( const std::pair<cahr, int> &p)
{
	std::cout << p.first << ":" << p.second<< std::endl;
}
int main()
{
	std::map<char, int> stat;
	char ch;
	while (std::cin >> ch)
	{
		++stat[ch]; // log műv, nincs kiindexelés
	}
	std::for_each(stat.begin(), stat.end(), &print); // & nem kötelező
}