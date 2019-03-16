/* https://www.facebook.com/groups/1697853153792345/permalink/1874640422780283/
attila: 01.04-ei vizsgán a find függvénybe (négyesért) kéne egy kis segítség.
Ugye ws.find( "Haskell" )-ra elvileg semmit nem találunk(nincs ilyen a settbe), de utána "Hello" == *wi mégis ez szerepel a feltételbe, esetleg valaki tudna mutatni egy helyes megoldást?

husi: http://pastebin.com/tLdqPWLw talán az 5öshöz less<T> kéne alapértelmezésbe, de whatever, így is kiírja
*/

#ifndef OEMSET_H
#define OEMSET_H

#include <set>
#include <algorithm>

template <class T>
struct Equal
{
    bool operator()(const T& lhs, const T& rhs)
    {
        return lhs == rhs;
    }
};

template <class T, class DefaultCompr, class EqualCompr = Equal<T>>
class optional_equality_multiset
{
    std::multiset<T, DefaultCompr> s;
    bool isEqualOn;
public:
    typedef typename std::multiset<T, DefaultCompr>::const_iterator const_iterator;

    optional_equality_multiset() : isEqualOn(false) {}
    void insert(const T &data)
    {
        s.insert(data);
    }
    unsigned count(const T &key) const
    {
        if (isEqualOn == false)
            return s.count(key);
        else
            return std::count_if(s.begin(), s.end(), [&](const T &value){return EqualCompr()(value, key);});
    }
    void use_equality()
    {
        isEqualOn = true;
    }
    void use_equivalence()
    {
        isEqualOn = false;
    }
    void erase(const T &key)
    {
        if (isEqualOn == false)
            s.erase(key);
        else
        {
            const_iterator begin = std::find(s.begin(), s.end(), key), end = begin;
            while(end != s.end() && EqualCompr()(*end, *begin))
                ++end;
            s.erase(begin, end);
        }
    }

    const_iterator find(const T& key) const
    {
        if(isEqualOn == false)
            return s.find(key);
        else
            return std::find_if(s.begin(), s.end(), [&](const T &value){return EqualCompr()(value, key);});
    }

    const_iterator begin() const
    {
        return s.begin();
    }
    const_iterator end() const
    {
        return s.end();
    }

    template <class Compr = DefaultCompr>
    operator std::multiset<T, Compr>() const
    {
        return std::multiset<T, Compr>(s.begin(), s.end());
    }
};

#endif // OEMSET_H