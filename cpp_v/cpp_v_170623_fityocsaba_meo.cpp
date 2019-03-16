#ifndef VIVIEW_H_INCLUDE
#define VIVIEW_H_INCLUDE

#include <vector>
#include <algorithm>

template<class T>
class vector_index_view
{	
private:
    typename std::vector<T>::iterator beginv;
	std::vector<int> indexes;
	bool is_plus;
	
	void reverse(bool reversed)
	{
		is_plus = reversed;
		std::reverse(indexes.begin(), indexes.end());
	}
	
public:
	static const int npos = -1;
	
	vector_index_view(std::vector<T> &vec) : beginv(vec.begin()), is_plus(true)
	{		
		for (int i = 0; i < vec.size(); ++i)
			indexes.push_back(i);
	}
	
	void swap(int a, int b)
	{
		std::swap(indexes[a], indexes[b]);
	}
	
	T& at(int i) const
	{
		return operator[](i);
	}
	
	T& operator[](int i) const
	{
		return *(beginv + indexes[i]);
	}
	
	int index_of(const T& elem) const
	{
		for (int i = 0; i < indexes.size(); ++i)
			if (operator[](i) == elem)
				return i;
		return npos;
	}
	
	void operator-()
	{
		if (is_plus)
			reverse(false);
	}
	
	void operator+()
	{
		if (!is_plus)
			reverse(true);
	}
	
	class iterator : public std::iterator<std::input_iterator_tag, T>
	{
	private:
		vector_index_view& viview;
		int index;

	public:
		iterator(vector_index_view& viv, int i) : viview(viv), index(i) {}
		
		bool operator==(iterator other) const
		{
			return index == other.index;
		}
		
		bool operator!=(iterator other) const
		{
			return !(*this == other);
		}
		
		iterator& operator++()
		{
			++index;
			return *this;
		}
		
		T& operator*() const
		{
			return viview[index];
		}
		
		T* operator->() const
		{
			return &operator*();
		}
	};
	
	iterator begin()
	{
		return iterator(*this, 0);
	}
	
	iterator end()
	{
		return iterator(*this, indexes.size());
	}
};

#endif // VIVIEW_H_INCLUDE