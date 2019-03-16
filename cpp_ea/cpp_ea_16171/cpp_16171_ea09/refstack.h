
// Referencia-számlálós stack template

#ifndef REFSTACK_H
#define REFSTACK_H

#include <iostream>

template <class T>
class stack
{
	// <> speciális jelölés: template friend
	friend std::ostream &operator<< <> ( std::ostream &os, const stack& s);
public:
		stack( int size = 128);
		stack( const stack &rhs);
		~stack();
	stack& operator=( const stack &rhs);

	void  push( const T& t);
	T     pop();

	bool empty() const;
	bool full()  const;
	int  size()  const;

	/* csak tesztelési célokkal: */
	void *test_address() const { return &(*r)[0]; }
private:
	// segédosztály: a stack megosztott része
	class rstack
	{
	public:
		rstack( int sz) : size(sz), cnt(0), v( new T[sz]) { }
		~rstack() { delete [] v; }

		int attach()  { return ++cnt; } // új megosztás
		int detach()  { return --cnt; } // lemond a megosztásról 
		bool shared() const { return cnt>1; } // ez az objektum megosztott

		T&  operator[](int i)   { return v[i]; }    // segédfv
		rstack *clone( int sp) const; // megosztott terület másolása
	private:
		// rstack csak a clone()-al másolható
			 rstack( const rstack &);
		void operator=( const rstack &);

		int size;
		int cnt;
		T   *v;
	};

	int     capacity;   // valójában redundáns: lehetne r->size
	int     sp;         // saját aktuális elemek száma
	rstack  *r;         // a megosztott terület

	void copy( const stack &other);
	void release();
};

template <class T>
typename stack<T>::rstack *stack<T>::rstack::clone( int sp) const
{
   rstack *p = new rstack(size);
   for ( int i = 0; i < sp; ++i )
		p->v[i] = v[i];
   return p;
}

template <class T>
stack<T>::stack( int size) : capacity(size), sp(0)
{
	r = new rstack(capacity);
	r->attach();
}
template <class T>
stack<T>::stack( const stack &other)
{
	copy(other);
}
template <class T>
stack<T>::~stack()
{
	 release();
}
template <class T>
stack<T>& stack<T>::operator=( const stack &other)
{
	// még ez sem kivétel-biztos
	if ( this != &other )
	{
		release();
		copy(other);
	}
	return *this;
}
template <class T>
void stack<T>::copy( const stack &other)
{
	capacity = other.capacity;  // capacity tárolható csak rstack-ben
	sp = other.sp;
	r  = other.r;
	r->attach();
}
template <class T>
void stack<T>::release()
{
	if ( r->shared() )
		r->detach();
	else
		delete r;
	// másik lehetőség: ha a megosztott számláló nullára csökken, 
	// akkor rstack "öngyilkosságot" követ el
}
template <class T>
void stack<T>::push( const T& t)
{
	if ( r->shared() )
	{
		r->detach();
		r = r->clone(sp);
		r->attach();
	}
	(*r)[sp++] = t;
}
template <class T>
T stack<T>::pop()
{
	return (*r)[--sp];
}
template <class T>
bool stack<T>::empty() const
{
	return 0 == sp;
}
template <class T>
bool stack<T>::full() const
{
	return capacity == sp;
}
template <class T>
int stack<T>::size() const
{
	return sp;
}
template <class T>
std::ostream &operator<<( std::ostream &os, const stack<T>& ds)
{
	os << "[ ";
	for ( int i = 0; i < ds.sp-1; ++i )
		os << (*ds.r)[i] << ", ";
	if ( ds.sp > 0 )
		os << (*ds.r)[ds.sp-1];
	os << " ]";
	return os;
}

#endif /* REFSTACK_H */

