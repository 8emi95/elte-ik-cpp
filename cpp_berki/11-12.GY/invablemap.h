#ifndef __INVABLEMAP_H__
#define __INVABLEMAP_H__

#include <map>

template <class K, class V, class Compare = std::less<K>, class InvCompare = std::less<V> >
class invertable_map{
std::map<K, V, Compare> m;
public:
	void insert(const K& k, const V& v) {
		m.insert(std::make_pair(k, v));
	}
	
	size_t size() const {
		return m.size();
	}
	
	size_t count(const K& v) const {
		return m.count(v);
	} 
	
	invertable_map<V, K, InvCompare, Compare> inverse() const {
		invertable_map<V, K, InvCompare, Compare> result;
		for(typename std::map<K,V, InvCompare>::const_iterator  cit = m.begin(); cit != m.end(); ++cit)
		{
			result.insert(cit->second, cit->first);
		}		
		return result;
	}

	invertable_map<V, K, InvCompare, Compare> operator-() const {
		return inverse();
	}

	
	V& operator[](const K& key )
	{
		return m[key];
	}
	
	const V& operator[](const K& key ) const
	{
		return m.find(key)->second;
	}
	
	operator std::map<K,V, Compare>() const { return m; }
};
#endif