2016.12.05.
12. C++ EA

-------------------------------------------------------------------
C++ Standard Template Library, generikus programozás:
-------------------------------------------------------------------

OOP

[Base]
  ^
[] [der?] []
^    ^
[]   []

Base *p = 0;



C++ STL:
[konténerek] [algoritmusok]


int *find(int *first, int *last, int x)
{
	while (first != last)
	{
		if (*first == x)
		{
			return furst;
		}
		++first;
	}
	return 0;
}


template<class T>
T *find(T *first, T *last, const T &t)
{
	while(first != last)
	{
		if (*first == t)
		{
			return first;
		}
		++first;
	}
	return 0;
}


template<class T>
Iter find(Iter first, Iter last, const T &t)
{							// [	  )
	while (first != last)	// first last
	{
		if (*first == t)
		{
			return first;
		}
		++first;
	}
	return last;
}


int v[] = {3, 8, 2, 5};
int *p = find(v, v + sizeof(v) / sizeof(v[0]), 4);
std::list<date> c;
std::list<date>::iterator i = find(c.begin(), c.end(), "2016.12.5");



Konténerek:
-----------
- szekvenciális: list, vector, deque, string			push_back, pop_back, push_front, pop_front, insert // ?
- asszociatív: set, multiset, map, multimap, insertlist (rendezettek jellemzően)
műveletigény garanciák					piros-fekete fák

list
--------ˇ
ˇ--------
[]	[]	[]	[]
    ^--------
    ---------^


vector
[] capacity

deque
 ------>[]
[]----->[]
 ------>[]



Konténer adaptor:
-----------------
stack, queue, priority-queue -> nincs iterátor


Iterátorok:
------------
- iterator (~T*)
- const_iterator (const T*)
- reverse_iterator (rbegin(), rend())
- const_reverse_iterator


int v[] = {9, 1, 3, 5};
int *p = v;
*p = 9;
std::vector<int> v(5);
std::vector<int>::iterator i = v.begin();
*i = 8;



template<class InputIterator, class Pred>
InputIterator find_if(InputIterator first, InputIterator last, Pred p)
{
	while (first != last)
	{
		if (p(*first)) // fvhívás: fvre mutató pointer bool(*f)(int)
		{				// funktor: Foo
			return first;
		}
		++first
	}
	return last;
}

bool f(int i)
{
	return i < 6
}

std::deque<int> d;
std::deque<int>::iterator i = find_if(.begin(), d.end(), f);


class Foo
{
	int x;
public:
	Foo(int i) : x(i) {}
	bool operator()(int s) const
	{
		return s < x;
	}
};