#ifndef DATE_H
#define DATE_H

#include <iostream>

/* 
 * egy egyszerű dátum típus 
 *
 * egy bonyolulthoz lásd:
 * http://www3.sympatico.ca/date4cpp/index.html
 *
 */
class date
{
public:
	/* konstruktorok */
	date( int y=2000, int m=1, int d=1) { set( y, m, d); } // inline fv
	date( const char *s);

	/* lekérdezések */
	int  get_year()  const { return year; }
	int  get_month() const { return month; }
	int  get_day()   const { return day; }

	/* módosító műveletek */
	date&  set_year( int y)  { year  = y; return *this; }
	date&  set_month( int m) { month = m; return *this; }
	date&  set_day( int d)   { day   = d; return *this; }

	date& next();
	date& add( int n);

	/* operátorok */
	date& operator++()       { return next(); }
	date  operator++(int)    { date curr(*this); next(); return curr; }; // postfix
	date& operator+=( int n) { return add(n); }

	/* beolvasás - kivitel */
	void get( std::istream& is);
	void put( std::ostream& os) const;

private:
	/* segéd-függvények */
	void set( int y, int m, int d)
	{
		/* TODO: ellenőrzések */
		year = y; month = m; day = d;
	}
	/* adattagok */
	int year;
	int month;
	int day;
};

/* globális műveletek az osztályon */
bool operator<( date d1, date d2);
inline bool operator==( date d1, date d2) { return !(d1<d2 || d2<d1); }
inline bool operator!=( date d1, date d2) { return d1<d2 || d2<d1; }
inline bool operator<=( date d1, date d2) { return !(d2<d1); }
inline bool operator>=( date d1, date d2) { return !(d1<d2); }
inline bool operator>( date d1, date d2)  { return d2<d1; }

/* beolvasó és kiíró operátor */
std::istream& operator>>( std::istream& is, date& d);
std::ostream& operator<<( std::ostream& os, const date &d);

#endif /* DATE_H */
