#include <iostream>

void f( int x, int* y, int& z )
{
   int s = x + (*y) + z;
   x = *y = z = s;
}

int main()
{
   int a = 1;
   int b = 2;
   int c = 3;
   f( a, &b, c );
   std::cout << a << b << c << std::endl;
}