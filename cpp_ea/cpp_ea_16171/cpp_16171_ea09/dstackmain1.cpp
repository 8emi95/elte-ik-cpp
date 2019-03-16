// dstack kliens program

#include <iostream>
#include "dstack1.h"

using namespace std;

int main()
{
	dstack d1(10);
	d1.push(3.14);    d1.push(4.14);    d1.push(5.14);
	cout << d1 << endl;
	dstack d2(d1); // ugyanaz, mint: dstack d2 = d1;

	while ( ! d1.is_empty() )
		cout << "pop: " << d1.pop() << endl;

	cout << d1 << endl;
	cout << d2 << endl;
	return 0;
}

/* output:

[ 3.14, 4.14, 5.14 ]
pop: 5.14
pop: 4.14
pop: 3.14
[  ]
[ 3.14, 4.14, 5.14 ]

*/
