2016.12.12.
13. C++ EA

---------------------------------------------------
Kivételkezelés: C++ 11
---------------------------------------------------
C-ben nem létezett

std::vector

- operator[]: nem végez ellenőrzést
std::vector<int> v;
for (int i = 0; i < v.size(); ++i)
{
	v[i] = 0;
}

- at:	- végez ellenőrzést
		- out_of_range típusú kivételt válthat ki

template<class T, ...>
class vector
{
	T *p;
public:
	T &at(int idx)
	{
		if (idx < 0 || idx >= size())
		{
			throw out_of_range();
		}
		return p[idx]
	}
	const T& at(int idx) const
	{
		if (idx < 0 || idx >= size())
		{
			throw out_of_range();
		}
		return p[idx];
	}
};

std::vector<int> v;
v.at(3) = 4;	// 0   3
				// [][][][]
++v.at(2);


std::exception
- poliformikus típusú
- virtual what() metódus


x.cpp		y.c 			z.cpp
	ˇ--->	f()		------^	void g() ... {...}
			{
				g();
			}


try
{
	...
}
catch(exception &e)
{
	std::cerr << e.what();
}


slicing

exception		matrix exception
  ___________________
[]______________[]___
				[]
				[]
				[]

try { ... }
catch(exception e) { ... }


try { ... }
catch(matrix_exception &e) { ... }
catch(exception &e) { ... }
catch(...) { ... }

f() -> g() -> h()
			kivétel
  ^---  ^---


try
{
	int p = new int[10]; // legyen aut változó mögött, pl smart pointer
	delete[] p;
}
catch(exception &e)
{
	delete[] p;
}


C++11
- move szemantika


std::string answer(std::string q)
{				// const std::string &q
	std::cout << g;
	std::string ans;
	std::cin.getline(ans);
	return ans; // copy ctor
}


auto ptr, 2003-as
			smart pointer

			auto ptr
			[]
copy ctor   v
			[] ---> [] heap


std::string&& answer(const std::string &q)
{
	std::cout << q;
	std::string ans;
	std::cin.getline(ans);
	return std::move(ans);
}


smart pointerek: depricated auto_ptr
----------------
- unique_ptr<T>: nem másolható, move-olható
- shared_ptr<T>: referencia számlált.


lambda-kifejezések/függvények:
------------------------------

std::list<int> c;
std::list<int>::iterator i = std::find_if(c.begin(), c.end(), Pred());
struct Pred
{
	bool operator()(int x) const
	{
		return x <5;
	}
};

-> funktorra fordul


STL:
----
- algoritmusok (pl copy_if)
- konténerek (pl forward_list)

auto/decltype(?)
auto it = std::find_if(c.begin(), c.end(), Pred());
std::vector<int> v;
auto a = v[2]; // auto &a = v[2];
// auto = int		decltype: referencia