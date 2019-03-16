/* https://www.facebook.com/groups/1697853153792345/permalink/1865048483739477/
Megtaláltam a 20-ai vizsgát, úgyhogy feltöltöm az 5-ösig a megoldást, ha nagyon nem érthető szivesen felrakom kommentelve is, a feladat ugye annyi volt, hogy egy tömb "view"-t kellet csinálni, vagyis amíg a tömbre ráhúzott "sorted_array_view" objektum él, addig a tömböt rendezettnek "látjuk" és ha megszűnik, akkor álljon vissza a tömb az eredeti állapotra. (destruktorban visszaállítani)
A sorted_array vector kihagyható a kódból, de már nem volt kedvem vele szórakozni, a "Less" helyett pedig lehetne std::less-t használni.

husi: az std::less biztosan nem 98as? :D Szerintem simán az
nándor: Igen kozben en is megneztem, akkor rosszul emlekeztem 

husi: Sajnos vizsgán egyáltalán nem fogadják el azt, ha egyszerre két konténerbe tárol az ember :( Legalábbis, ha ugyanazaokat az elemeket, csak máshogy tárolják :( Ezt látom hogy ki is írtad, tényleg no hate, csak érdemes figyelni rá :)
nándor: Nekem nem szoltak be erte, csak megkerdeztek, hogy miert kellett ketto. De elmagyaraztam, hogy az egyik kvazi felesleges es azt mondtak, hogy rendben semmi gaz.
husi: Na akkor szuper :D (én pl. voltam olyan csacsi hogy amikor vizsgáztam 4 multimapot használtma, és azért elküldtek az anyámba)
*/

#ifndef SA_VIEW_H
#define SA_VIEW_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
struct Less {
	bool operator()(T t1, T t2) const {
		return t1 < t2;
	}
};

template<typename Type, typename Func = Less<Type> > class sorted_array_view {
	private:
	Type* array;
	std::vector<Type> unsorted_array;
	std::vector<Type> sorted_array;
	Func functor;
	int array_size;
	
	public:
	typedef typename std::vector<Type>::const_iterator iter;
	
	const static int npos = -1;
	
	sorted_array_view(Type* array, int array_size) : array_size(array_size), array(array), unsorted_array(array, array+array_size), sorted_array(array, array+array_size) {
		std::sort(sorted_array.begin(), sorted_array.end(), functor);
		std::sort(array, array+array_size, functor);
	}
	
	const int size() const {
		return sorted_array.size();
	}
	
	~sorted_array_view() {
		std::copy(unsorted_array.begin(), unsorted_array.end(), array);
	}
	iter begin() const {
		return sorted_array.begin();
	}
	iter end() const {
		return sorted_array.end();
	}
	
	int count(Type t) const {
		int c = 0;
		for (int i = 0; i < array_size; ++i) {
			if ((!( array[i] < t ) && !( t < array[i] ))) {
				++c;
			}
		}
		return c;
	}
	
	int index_of(Type t) const {
		int index = npos;
		bool found = false;
		for (int i = 0; i < array_size && !found; ++i) {
			if ((!( array[i] < t ) && !( t < array[i] ))) {
				found = true;
				index = i;
			}
		}
		return index;
	}
	template<typename SeqContainer>
	void copy (SeqContainer& c) const {
		c.clear();
		std::copy(array, array+array_size, std::back_inserter(c));
	}
};
#endif