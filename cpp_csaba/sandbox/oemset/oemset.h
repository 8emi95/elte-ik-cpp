#ifndef OEMSET_H
#define OEMSET_H

#include <iostream>
#include <set>
#include <algorithm>

template <typename TContainer>
void printC(const TContainer &cont) // print container contents
{
    typename TContainer::const_iterator it = cont.begin();
    for (it = cont.begin(); it != cont.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

template <class T>
struct Equal
{
    bool operator()(const T &lhs, const T &rhs)
    {
        return lhs == rhs;
    }
};

template <typename T, typename Comp>
class optional_equality_multiset
{
  public:
    optional_equality_multiset() : let_equals(false)
    {
    }

    optional_equality_multiset(const optional_equality_multiset<T, Comp> &other) : let_equals(other.let_equals), set(other.set)
    {
    }

    void insert(const T &value)
    {
        set.insert(value);
    }

    void use_equality()
    {
        let_equals = true;
    }
    void use_equivalence()
    {
        let_equals = false;
    }

    size_t count(const T &val) const
    {
        if (let_equals)
        {
            typename std::multiset<T, Comp>::iterator it;
            int ret = 0;
            for (it = set.begin(); it != set.end(); ++it)
            {
                if (userComparator(*it, val))
                    ++ret;
            }
            return ret;
        }
        else
        {
            return set.count(val);
        }
    }

    void erase(const T &val)
    {
        printC(set);        
        if (let_equals)
        {
            // typename std::multiset<T, Comp>::const_iterator begin = std::find(set.begin(), set.end(), val), end = begin;
            // while (end != set.end() && equalComparator(*end, *begin))
            //     ++end;
            // set.erase(begin, end);
        }
        else
        {
            set.erase(val);
        }
        printC(set);
    }

  private:
    bool let_equals;
    std::multiset<T, Comp> set;
    Comp userComparator;
    Equal<T> equalComparator;
};

#endif