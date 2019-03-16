#ifndef __TEMPLATE_CLASS_H__
#define __TEMPLATE_CLASS_H__

#include <iosfwd>

template <typename T>
class Store
{
	T t;
public:
	Store(const T& t) : t(t) {}
	
	void print()
	{
		std::cout<<t<<std::endl;
	}
	
	void uppercase()
	{
		for(typename T::iterator it = t.begin(); it != t.end(); ++it)
			*it = toupper(*it);
	}
};

#endif //__TEMPLATE_CLASS_H__
