//
// _naive_ dstack osztály
// vigyázat! hibás kód
//
#ifndef DSTACK_H
#define DSTACK_H

#include <iostream>

class dstack
{
	/* friend deklaráció: nem helyettesíti a függvény deklarációt */
	friend std::ostream &operator<<( std::ostream &os, dstack ds);
public:
		/* konstruktor */
		dstack( int size = 128);

	void   push( double d);
	/* a legtöbb könyvtárban: void pop() */
	double pop();
	/* a legtöbb könyvtárban lenne még:
	double& top();
	double  top() const;
	*/
	bool is_empty() const;
	bool is_full() const;
private:
	int    capacity;    // lefoglalt tárterület mérete
	int    sp;          // aktuális elemek száma
	double *v;          // pointer a tárterületre
};
/* a kiíró művelet deklarációja (friend nem elég) */
std::ostream &operator<<( std::ostream &os, dstack ds);

#endif /* DSTACK_H */
