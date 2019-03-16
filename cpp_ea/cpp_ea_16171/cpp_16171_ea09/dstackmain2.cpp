#include <iostream>
#include "dstack2.h"

using namespace std;

int main()
{
	dstack d1(10);  // Konstruktor: d1.dstack(10)
	d1.push(3.14);    d1.push(4.14);    d1.push(5.14);
	cout << d1 << endl;
	dstack d2(d1);  // Másoló konstruktor: d2.dstack(d1)

	while ( ! d1.is_empty() )
		cout << "pop: " << d1.pop() << endl;

	d1.push(6.14);

	cout << d1 << endl;
	cout << d2 << endl;

	d1 = d2;   // Értékadás: d1.operator=(d2)
	cout << d1 << endl;
	return 0;
}   // Destruktor: d2.~dstack(); d1.~dstack()

/* Output:

[ 3.14, 4.14, 5.14 ]
pop: 5.14
pop: 4.14
pop: 3.14
[ 6.14 ]
[ 3.14, 4.14, 5.14 ]
[ 3.14, 4.14, 5.14 ]

*/