#include <iostream>

int b; // globalis valtozo, statikus, stack

void method ( int c 
					 /*parameter (lemasolodik), lokalis, automatikus, stack*/, 
					int &d
					/*parameter, referencia, nem masolja le a metodus, 
					a tarolas az eredeti valtozoval megegyezo*/ 
					)
{
	int *f = new int; /*lokalis, automatikus, stack, 
							a mutato altal cimzett memoriaterulet
							globalis, free store, heap
							*/
	*f = 6;
	for(int i = 0; // lokalis valtozo, automatikus, stack
			i < 5; ++i)
	{
	} // i megszunik
	if(c == 5)
	{
		int e; // lokalis valtozo, automatikus, stack
	} // e megszunik
	*f = 8;
	delete f; // az f altal mutatott memoriateruletet felszabaditjuk
	*f = 7; // nem definialt viselkedes
	
} // c,f megszunik 

void method(int* b /*parameter, lokalis, automatikus, stack
								a pointert lemasoljuk, a mogotte levo valtozot nem! */ )
{
	*b = 6; 
	++b;  
	*b = 7; // nem definialt viselkedes, csak a parameteratadas miatt nezzuk mi tortenik
} // a lemasolt b megszunik


int main()
{
	int a; // lokalis valtozo, automatikus, stack
	int* b = new int; //lokalis valtozo, 
	*b = 5;
	std::cout<<b<<" "<<*b<<std::endl;
	method(b);
	std::cout<<b<<" "<<*b<<std::endl;
	std::cout<<b+1<<" "<<*(b+1)<<std::endl; // nem definialt viselkedes
	return 0;
} // a megszunik, b nem, csak a program futasa vegen