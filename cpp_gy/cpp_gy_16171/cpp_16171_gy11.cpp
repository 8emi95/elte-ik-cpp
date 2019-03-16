2016.11.30.
11. C++ GY

------------------------------------------
Sablonok, C++-template-ek:
------------------------------------------

int printf(char *format, ...); // változók értékétlehet kiírni, formázó stringet vár, akárhány paramétert lehet kiírni

int i = 3;
double d = 2.16;
printf("%d\n", i);
printf("%f\n", d);

void *malloc(int bytes);

void free(void *ptr);
		// memóriacím típustalanul
		// ...

#define MAX(a, b) ((a) < (b) ? (b) : (a))


// C++:
template<class T>
const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}
//---
std::cout << max(5, 7);

paraméter T ekviv int, dedukció
példányosítás / instantiation

std::cout << max(3, 89, 8.1)
T == double
std::cout << max(2.5, 14) // ford hiba, kötelezően meg kell egyezni a 2 típusnak


class complex
{
	// ...
}; // nincs operator<

complex a(1.4, 3.5);
complex b(3.7, 1.5);
complex c = max(a, b);
T ekviv complex
ford hiba

std::list<int> c;
std::sort(c.begin(), c.end()); // ford hiba

// láncolt lista, bidirectional
[] <=> [] <=> [] <=> [] <=> []
1.     2.     3.     4.     5.

[]		[][][]
^		^
p	++	p

random access iterátort vár

c.sort(); // működik

std::cout << max("banan", "korte"); // nem definiált h mit ír ki, banan/korte
				// const char[6]
std::cout << max("alma", "korte"); // ford hiba, más méret és típus
std::cout << max<std::string>("alma", "korte"); // lemondunk a paraméterdedukcióról, lexikografikus rendezés: korte
std::cout << max<double>(1.1, 6); // 6.0, explicit specializáció

template<class InputIterator, class Fun>
Fun for_each(InputIterator first, InputIterator last, Fun f)
{
	while (first != last)
	{
		f(*first++)
	}
	return f;
}

InputIterator: first, last
- operator!=					pointer-aritmetika alapján pl. pointerek
- operator!++(int)				STL-es adatszerkezetek belő iterátor típusai is használhatóak
- operator*
(- copy ctor)

Fun:
(- copy ctor)					pl fv-re mutató pointer
- fv-hívás						funktor-típusok, unáris funktor


template<class T>
class Print
{
	std::ostream &os;
public:
	Print(std::ostream &o) : os(o) {}
	void operator(const T& t) //template
	{
		os << t << ' ';
	}
};

Print<double> // template
pd(std::cerr); // kiírja std.error-ra
pd(1.23);
pd("blabla"); // ford hiba
std::for_each(v.begin(), v.end(), Print<int>(std::cerr));


clas Print
{
	std::ostream &os;
public:
	Print(std::ostream &o) : os(o) {}
	template<class T>
	void operator()(const T& t) //template
	{
		os << t << ' ';
	}
};

Print p(std::cout); // Print(), ctor-hívás
p(6);
p("Hello");
p(4.23);
p(std::list<int>()); // ford hiba


Java: generikusok