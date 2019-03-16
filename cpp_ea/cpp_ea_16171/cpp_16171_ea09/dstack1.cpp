// _naive_ dstack implementáció

#include <iostream>
#include "dstack1.h"

dstack::dstack( int size)
{
	/* ugyanaz, mint 
	   capacity = size;
	   v = new double[capacity];
	 */
	v = new double[capacity = size];
	sp = 0;
}
void dstack::push( double d)
{
	// TODO?: hibakezelés
	if ( ! is_full() )
		v[sp++] = d;
}
double dstack::pop()
{
	// TODO?: hibakezelés
	return is_empty() ? 0.0 : v[--sp];
}
// a szabványos könyvtárban: bool empty() const
bool dstack::is_empty() const
{
	return 0 == sp;
}
bool dstack::is_full() const
{
	return capacity == sp;
}
std::ostream &operator<<( std::ostream &os, dstack ds)
{
	os << "[ ";
	for ( int i = 0; i < ds.sp-1; ++i )
		os << ds.v[i] << ", ";

	// hogy ne írjunk vesszőt az utolsó elem után:    
	if ( ds.sp > 0 )
		os << ds.v[ds.sp-1];
	os << " ]";

	return os;
}
