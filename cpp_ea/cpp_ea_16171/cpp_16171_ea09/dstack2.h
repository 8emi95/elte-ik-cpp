
// nagyjából helyes dstack definíció

#ifndef DSTACK_H
#define DSTACK_H

#include <iostream>

class dstack
{
		friend std::ostream &operator<<( std::ostream &os, dstack ds);
public:
					 dstack( int size = 128);
					 dstack( const dstack &other);     // ver2: másoló konstruktor 
					 ~dstack();                        // ver2: destruktor         
		dstack& operator=( const dstack &other); // ver2: értékadó operátor  

		void   push( double d);
		double pop();

		bool is_empty() const;
		bool is_full()  const;
private:
		int    capacity;
		int    sp;
		double *v;

		void copy( const dstack &other);  // ver2: inicializálás és másolás  
};
std::ostream &operator<<( std::ostream &os, dstack ds);

#endif /* DSTACK_H */
