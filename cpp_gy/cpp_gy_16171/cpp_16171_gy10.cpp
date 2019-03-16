2016.11.23.
10. C++ GY

-------------------------------------
Operátorok túlterhelése:
-------------------------------------

Java: referenciaszemantika
String a;
String b;
if (a == b) {...} // ugyanarra az obj-ra hivatkozik-e
a.equals(b) // ugyanaz-e

Matrix m;
++m(1,2);
m.set(1, 2, m.get(1, 2) + 1);



túlterhelető operátorok:
------------------------
=
==
+
[] // indexelés
->
& // lehet de nem illik

nem túlterhelető operátorok:
----------------------------
. // mindig előjön h mi lenne ha engednénk, durva eszköz lesz ha megteszik
:: // scope, hatókörkiválasztás
sizeof
? :

// újat nem lehet bevezetni jelenleg (?)
fix aritással:
--------------
a+b // bináris
+x // unáris
// 3 paraméterrel nem lehet
kivétel: operator()



class Vector
{
	int cap.s;
	T *p;
public:
	int size() const
	{
		return s; // const Vector* const this (csak olvasni lehet)
	}
	T& operator[](int idx) // indexelő operátor
	{
		return p[idx]; // Vector* const this
	}
	const T& operator[](int idx)
	{
		return p[idx]; // const Vector* const this (csak olvasni lehet)
	}
};

Vector v(3)
++v[0];
............... // crap


Vector v(8);
const Vector c = v;
std::cout << c[2]; //const T& operator[](int idx) hívódik meg
std::cout << v[2];
++v[1];




class complex
{
	double re, im;
public:
	compley(double r = 0.0, double i = 0.0) : re(r), im(i) {}
	bool operator==(const complex &rhs) const // bal és jobb oldalon is állhat konstans
	{
		return re == rhs.re && im == rhs.im;
	} // *
};

complex s(2.91 1.1);
compley t(1.6, 1.8);
if (s == t) {...}
//       ˇs.operator==(t)
//     ˇoperator==(s,t)

if (s == 1.7) {...}
//  ˇs.operator==(complex(1.7))
// lefordul

if (1.7 == s) {...}
//   1.7.operator==(s)
// ford hiba

complex n;
complex c(1.7);
// 1.7 + 0.0


// * bool kívülre
class complex {...};
bool operator==(const complex &lhs, const complex &rhs) // bal és obb odlali operandus
{
	return lhs.get.re() == rhs.get.re() && lhs.get.im() == rhs.get.im();
}




globális operátorként illik:
----------------------------
==
!=
+
*
-
<
>
<=
stb


Matrix m;
++m(1,2); // ++m.operator(1,2);
std::cout << m(1.2);
			 m();
			 m(1, 2, 3, 4);

void print(int x)
{
	std::cout << x << ' ';
}

std::vector<int> v;
std::for_each(v.begin(), v.end(), print);


class Print // funktortípus/-osztály
{
	std::ostream & os;
public:
	Print(std::ostream& o) : os(o) {}
	void operator()(int x)
	{
		os << x << ' ';
	}
};

Print pe(std::cerr); // ctor-hívás
pe(3); // "3 " (3 + szóköz)		} operator() fv
pe(8); // "8 "					}

Print p(std::cerr);
std::vector<int> v;
std::for_each(v.begin(), v.end(), p);
std::for_each(v.begin(), v.end(), Print(std::cout));


class Sum
{
	int s;
public:
	Sum(int i = 0) : s(i) {}
	void operator()(int x)
	{
		s += x;
	}
	int get_sum() const
	{
		return s;
	}
};


Sum a(3); // ctor hívás
a(3);	// }
a(3);	// } operator()
a(2);	// }
std:cout << a.get_sum(); // get.sum()
			// 11

std::vector<int> v;
std::cout << std::for_each(v.begin(), v.end(), Sum()).get_sum();