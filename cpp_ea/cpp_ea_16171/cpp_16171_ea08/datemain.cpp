#include <iostream>

#include "date.h"

using namespace std;

/* program a date osztály tesztelésére */
int main()
{
    date d;

    while ( cin >> d )
    {
        cout << (d+=40) << endl;
    }

    date d2(2004,3);

    if ( d < d2 )
        ++d;

    cout << d << endl;

    return 0;
}
