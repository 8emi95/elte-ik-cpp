#ifndef __CASE_STRING_H__
#define __CASE_STRING_H__

#include <string>

template <class T>
T tolow(T t)
{
	return tolower(t);
}

template <>
wchar_t tolow(wchar_t t)
{
	return towlower(t);
}


template <class T>
class case_insensitive_basic_string {
std::basic_string<T> s;

	static std::basic_string<T> tolows(std::basic_string<T> s)
	{
		std::basic_string<T> sl;
        for(typename std::basic_string<T>::const_iterator cit = s.begin(); cit != s.end(); ++cit)
        {
			sl.push_back(tolow(*cit));
        }
		return sl;
	}

public:

	static const int npos;
	
	void push_back(T t) {
		s.push_back(tolow(t));
	}
	
	size_t size() const {
		return s.size();
	}
	
	size_t find(T t) const {
		return s.find(tolow(t));
	}
	
	size_t find(const std::basic_string<T>& u) const {
		std::basic_string<T> v;
		for(int i = 0; i<u.size();++i)
			v.push_back(tolow(u[i]));
		return s.find(v);
	}
	
	size_t rfind(T t) const {
		return s.rfind(tolow(t));
	}
	
	size_t rfind(const std::basic_string<T>& u) const {
		std::basic_string<T> v;
		for(int i = 0; i<u.size();++i)
			v.push_back(tolow(u[i]));
		return s.rfind(v);
	}
	
	T& operator[](size_t pos) {
		return s[pos];
	}

	const T& operator[](size_t pos) const {
		return s[pos];
	}

		 bool operator==(const std::basic_string<T> &rhs) const
        {
            if (s.size() != rhs.size())
				return false;
			return (s == tolows(rhs));
        }

    bool operator==(const case_insensitive_basic_string<T> &rhs) const
    {
		if (s.size() != rhs.size())
		return false;
		return (s == rhs);
    }

    friend bool operator==(const std::basic_string<T> &lhs, const case_insensitive_basic_string<T> &rhs) 
    {
        if (rhs.size() != rhs.size())
		return false;
        return (rhs == tolows(lhs));
    }

};

typedef case_insensitive_basic_string<char> case_insensitive_string;

template <class T>
const int case_insensitive_basic_string<T>::npos = -1;
#endif 