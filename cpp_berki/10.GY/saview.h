#ifndef __SAVIEW_H__
#define __SAVIEW_H__

#include <vector>
#include <algorithm>

template <class T>
class sorted_array_view {
T* array;
int _size;
std::vector<T> orig;
public:
	sorted_array_view(T* t, int siz) : array(t), _size(siz), orig(t, t + siz) {
		std::sort(t, t +_size);
	}
	
	~sorted_array_view() {
		for(int i = 0; i < _size; ++i)
			array[i] = orig[i];
	}
	
	int size() const {
		return _size;
	}
};

#endif