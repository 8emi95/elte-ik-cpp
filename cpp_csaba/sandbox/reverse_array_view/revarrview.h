#ifndef REVARRVIEW_H
#define REVARRVIEW_H

#include <iostream>
#include <deque>

template <typename T>
class reverse_array_view
{
  public:
    reverse_array_view(T *array, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            arr.push_front((array + i));
        }
    }

    void add(T *array, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            arr.push_front((array + i));
        }
    }

    template <int N>
    void add(T (&array)[N])
    {
        for (int i = 0; i < N; ++i)
        {
            arr.push_front((array + i));
        }
    }

    template <typename Cont>
    void add(Cont &cont)
    {
        for (typename Cont::iterator it = cont.begin(); it != cont.end(); ++it)
        {
            arr.push_front(&*it);
        }
    }

    size_t size() const
    {
        return arr.size();
    }

    const T &at(int position) const
    {
        // std::cout << "at " << position << " :" << arr.at(position) << std::endl;
        return *arr.at(position);
    }

    const T &operator[](int position) const
    {
        return *arr[position];
    }
    T &operator[](int position)
    {
        return *arr[position];
    }

  private:
    std::deque<T *> arr;
};

#endif