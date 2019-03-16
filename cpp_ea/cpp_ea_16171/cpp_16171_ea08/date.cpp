#include <iostream>
#include <cstring>
#include <cstdlib>

#include "date.h"

using namespace std;

/* konstruktor */
date::date( const char *s)
{
    /* strchr és strrchr a <cstring>-ből */
    char *p1 = strchr( s, '.');
    char *p2 = strrchr( s, '.');

    if ( p1 && p2 && p1 != p2 )
    {
        /* atoi a <cstdlib>-ből> */
        int y = atoi(s);
        int m = atoi(p1+1);
        int d = atoi(p2+1);

        set( y, m, d);
    }
}

/* módosítók */
date& date::next()
{
    static int day_in_month[] =
              { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    ++day;

    /* TODO: szökőév */
    if ( day-1 == day_in_month[month-1])
    {
        day = 1;
        ++month;
    }
    if ( 13 == month )
    {
        month = 1;
        ++year;
    }
    return *this;
}
date& date::add( int n)
{
    for (int i = 0; i < n; ++i)
        next();
    return *this;
}

/* input-output */
void date::get( std::istream& is)
{
    // nem lenne igazán jó:
    // is >> year >> month >> day;
    int y, m, d;
    if ( is >> y >> m >> d )
    {
        set( y, m, d);
    }
}
void date::put( std::ostream& os) const
{
    // nem lenne igazán jó: os << year << month << day;
    os << "[ " << get_year() << "," << get_month()
                             << "," << get_day() << " ]";
}

/* globális műveletek */
bool operator<( date d1, date d2)
{
    return d1.get_year() < d2.get_year()  ||
           d1.get_year() == d2.get_year() && d1.get_month() < d2.get_month()  ||
           d1.get_year() == d2.get_year() && d1.get_month() == d2.get_month()
                                          && d1.get_day() < d2.get_day();

}
istream& operator>>( istream& is, date& d)
{
    d.get( is);
    return is;
}
ostream& operator<<( ostream& os, const date &d)
{
    d.put( os);
    return os;
}

