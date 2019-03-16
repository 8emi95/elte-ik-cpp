#ifndef SAVIEW_H
#define SAVIEW_H

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T, typename Comparer = std::less<T> >
class sorted_array_view
{
  public:
    sorted_array_view(T *array, size_t n) : target(array),
                                            original(array, array + n)
    {
        std::sort(array, array + n, Comparer());
    }

    ~sorted_array_view()
    {
        std::copy(original.begin(), original.end(), target);
    }

    int size() const
    {
        return original.size();
    }

    size_t count(const T &val) const
    {
        std::pair<const T *, const T *> eq_range = std::equal_range(target, target + original.size(), val, Comparer());
        return std::distance(eq_range.first, eq_range.second);
    }

    size_t index_of(const T &val) const
    {
        const std::pair<const T *, const T *> eq_range = std::equal_range(target, target + original.size(), val, Comparer());
        int distance =  std::distance(static_cast<const T *>(target), eq_range.first);
        return eq_range.first == eq_range.second ? npos : distance;
    }

    template <typename C>
    void copy(C &container) const
    {
        container.clear();
        std::copy(target, target + original.size(), std::inserter(container, container.end()));
    }

    const T* begin() const
    {
        return target;
    }

    const T* end() const
    {
        return target + original.size();
    }

    static const size_t npos = -1;

  private:
    T *target;
    std::vector<T> original;
};

#endif