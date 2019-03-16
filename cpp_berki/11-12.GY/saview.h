#ifndef __SAVIEW_H__
#define __SAVIEW_H__

#include <vector>
#include <algorithm>

template <class T, class Comp = std::less<T> >
class sorted_array_view {
T* array;
int _size;
std::vector<T> orig;
public:
	
	static const int npos;

	sorted_array_view(T* t, int siz) : array(t), _size(siz), orig(t, t + siz) {
		std::sort(t, t +_size, Comp());
	}
	
	~sorted_array_view() {
		for(int i = 0; i < _size; ++i)
			array[i] = orig[i];
	}
	
	int size() const {
		return _size;
	}
	
	int count(const T& t) const {
		int result = 0;
		for(int i = 0; i < _size; ++i)
			if (!Comp()(array[i],t)&&!(Comp()(t,array[i])))
				++result;
		return result;
	}
	
	int index_of(const T& t) const {
		for(int i = 0; i < _size; ++i)
			if (!Comp()(array[i],t)&&!Comp()(t,array[i]))
				return i;
		return npos;
	}
	
	template <class U>
	void copy(U& other) const {
		other.clear();
		for(int i = 0; i < _size; ++i)
			other.push_back(array[i]);
	}
	
	const T* begin() const
	{
		return array;
	}
	
	const T* end() const
	{
		return array+_size;
	}
};

template <class T, class U>
const int sorted_array_view<T, U>::npos = -1;

#endif