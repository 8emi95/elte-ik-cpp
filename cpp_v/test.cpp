#include <iostream>
#include <string>

/*int a;
float b;
long c;
std::string d;
char e;
bool f;*/

/*int & addOne (int &i)
{
	i++;
	return i;
}*/

/*struct Foo
{
    int a, b;
    Foo(int c):a(c*2),b(c*3) {}
};*/

	void f(int& x, int& y)
	{
		int t = x;
		x = y;
		y = t;
	}

int main()
{
	// std::cout << a << "int, " << b << "float, " << c << "long, " << d << "string, " << e << "char, " << f << "bool" << std::endl;

/*	int a = 1;
	// int p = &a; // int -> int*
	int* p = &a;
	*p = 2;
	std::cout << a << " " << p << " " << *p << std::endl;*/

/*	int i = 0;
	int a = addOne (i);
	std::cout << a << std::endl;*/

/*	int i = 5;
	int t[] = {5, 4, 3, 2, 1};
	std::cout << sizeof (i) << std::endl; // 4
	std::cout << sizeof (t) << std::endl; // 20

	for (int i = 0; i < 6; i++) // Hupsz . A csak 5 elem van .
	{
		std :: cout << t[i] << std :: endl ;
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << i << ": " << ++t[i] << std::endl;
	}
	std::cout << " sajt " << std::endl;*/

/*	int t[] = {5, 4, 3, 2, 1};
	int isAdmin = 0;
	std::string name;
	std::cin >> name;
	for (int i = 0; i < name.size(); ++i)
	{
		t[i] = 1;
	}
	if (name == "pityu")
		isAdmin = 1;
	std::cout << "Admin?: " << (isAdmin != 0) << std::endl;*/

/*	int t[] = {6 ,4 ,3 ,2 ,1};
	int *p = t;
	std :: cout << *p << std :: endl ; // 5
	std :: cout << sizeof (int ) << std :: endl ; // implement ációfüggo, legyen x
	std :: cout << sizeof (p) << std :: endl ; // implement ációfüggo, legyen y
	std :: cout << sizeof (t) << std :: endl ; // 5*x
	std :: cout << sizeof (*p) << std :: endl ;*/

/*	char* hello = "Hello";
	hello [1] = 'o';
	std::cout << hello << std::endl;*/

/*	Foo f(5);
	std::cout << f.b;*/

	int a = 1;

	f(a,2);
	std::cout << a;

	std::string exit;
	std::cin >> exit;
	// std::cin.get();
	return 0;
}