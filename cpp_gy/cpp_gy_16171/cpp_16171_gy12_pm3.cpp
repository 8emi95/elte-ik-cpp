2016.12.07.
12. C++ GY

+/-: fvsablon, 2 azonos típusú pm-t vár, felcseréli pm-eket
template<class T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = temp;
}


-------------------------------------------------
Öröklődés:
-------------------------------------------------
- kódújrafelhasználás
- (altípusos) polimorfizmus

std::vector<int> v(3); // lefordul
std::string s(3); // ford hiba
std::string x(0); // lefordul, fut hiba, 0 nullpointer (nem hossz)
std::string msg("Hello"); 

class safe_string
{
	std::string s;
public:
	safe_string(const char *p) : s(p ? p : "") {}
	int size() const
	{
		return s.size();
	}
	void push_back(char ch)
	{
		s.push_back(ch);
	}
};

class safe_string: public std::string
{
public:
	safe_string(const char *p) : std::string(p ? p : "") {}
};

safe_string a(0);
a.push_back('a');
std::cout << a.size();



class Base
{
public:
	virtual void f() const // Base polimorfikus
	{
		std::cout << "Base::f()";
	}
	virtual ~Base() {}
	virtual Base *clone() const
	{
		return new Base(...);
	}
};

struct Der : Base
{
	virtual void f() const // mindegy h kiírom-e a virtualt, mert a Base miatt nem lehet megváltoztatni
	{
		std::cout << "Der::f()";
	}
	virtual ~Der() {}
	virtual Der *clone() const
	{
		return new Der(...);
	}
};

Base *p = 0; // Base *p - statikus típus
p = new Base(); // new Base() - dinamikus típus -> futási időben változhat
p -> f(); // Base::f()
delete p; // ~Base()
p = new Der();
p -> f(); // Der::f()
delete p; // ~Der(), ~Base()

void g(Base *p)
{
	p -> f();
} // lefordítható

Base b;
b.f(); // Base::f()
Der d;
d.f(); // Der::f()

void fv(Base b) // slicing
{
	b.f(); // Base::f()
}

Base		Subtype
[]			[]			[]
[]			[]			[]
[]			[]			[] slicing
			[]
			[]
			[]

void fv_ok(Base &b)
{
	b.f();
}

Base *q = p -> clone();
delete q;



class Shape // absztrakt osztály
{
	int color; // színkód
public:
	Shape(int i) : color(i) {}
	virtual ~Shape() {}
	virtual double area() const = 0; // = 0 miatt pure virtual, emiatt lesz absztrakt, nem lehet Shape obj-ot létrehozni
	int get_color() const
	{
		return color;
	}
};

void print(Shape *s)
{				// int get_color() const
	std::cout << s -> get_color() << ' ' << s -> area(); // area - alítpushelyesen
} // lefordítható

template<class Síkidom>
void print(const Síkidom &s)
{
	std::cout <<s.get_color() << ' ' << s.area();
} // nem fordítható


class Circle : public Shape
{
	double r;
public:
	int get_color() const { return 0; }
	Circle(int c, double rad) : Shape(c), r(rad) {} // int get_color() const { return 0; }
	virtual ~Circle() {}
	virtual double area() const
	{
		return r * r * 3.14;
	}
};

Circle c(3.15);
print(&c); // szín: 3
c.get_color(); // szín: 0