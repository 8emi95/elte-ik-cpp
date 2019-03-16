#include <iostream>
#include "refstack.h"

using namespace std;

int main()
{
	stack<double> d1(10);
	d1.push(3.14);    d1.push(4.14);    d1.push(5.14);
	cout << d1 << endl;
	stack<double> d2(d1);   // másoló konstruktor másolás nélkül
	cout << d1.test_address() << ", " << d2.test_address() << endl;

	while ( ! d1.empty() )
		cout << "pop: " << d1.pop() << endl;

	cout << d1.test_address() << ", " << d2.test_address() << endl;

	d1.push(6.14);  // másolás itt
	cout << d1.test_address() << ", " << d2.test_address() << endl;
	cout << d1 << endl;
	cout << d2 << endl;

	d1 = d2;   // értékadás másolás nélkül
	cout << d1.test_address() << ", " << d2.test_address() << endl;
	cout << d1 << endl;

	return 0;
}

/* Output:

[ 3.14, 4.14, 5.14 ]
0x804a6b8, 0x804a6b8
pop: 5.14
pop: 4.14
pop: 3.14
0x804a6b8, 0x804a6b8
0x804a720, 0x804a6b8
[ 6.14 ]
[ 3.14, 4.14, 5.14 ]
0x804a6b8, 0x804a6b8
[ 3.14, 4.14, 5.14 ]

*/