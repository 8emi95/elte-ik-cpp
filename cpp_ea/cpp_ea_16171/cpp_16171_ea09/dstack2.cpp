#include <iostream>
#include "dstack2.h"

dstack::dstack( int size)
{
	v = new double[capacity = size];
	sp = 0;
}
dstack::dstack( const dstack &other)    /* ver2 */
{
	copy(other);
}
dstack::~dstack()                       /* ver2 */
{
	delete [] v;
}
dstack& dstack::operator=( const dstack &other) /* ver2 */
{
	if ( this != &other )   // x = x
	{
		// nem igazán kivétel-biztos
		delete [] v;
		copy(other);
	}
	return *this;
}
void dstack::copy( const dstack &other)
{
	v = new double[capacity = other.capacity];
	sp = other.sp;

	for ( int i = 0 ; i < sp; ++i)
		v[i] = other.v[i];
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
	if ( ds.sp > 0 )
		os << ds.v[ds.sp-1];
	os << " ]";

	return os;
}
