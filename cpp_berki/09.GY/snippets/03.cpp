#include <iostream>

void f( int* p, int n, int& r )
{
   r = 0;
   int *q = p;
   for( int i = 0; i < n; ++i )
   {
     r += *p;
     *p = p - q;
     ++p;
   }
}

int main() {
	int d[]= {3,4,5,6};
	int s;
	int n =sizeof(d)/sizeof(d[0]);
	f(d, n, s);
	std::cout<<s<<std::endl;
	for(int i=0; i<n; ++i)
		std::cout<<*(d+i)<<" ";
}