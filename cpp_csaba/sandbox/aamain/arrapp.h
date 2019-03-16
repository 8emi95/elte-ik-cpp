#ifndef ARRAPP_H
#define ARRAPP_H

#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

template <typename T>
class array_appender
{
  private:
    std::deque<T *> data;
    void appendData(T *arr, size_t n)
    {
        for (int i = 0; i < n; ++i)
        {
            data.push_back(arr + i);
        }
    }

  public:
    array_appender(T *arr, size_t n)
    {
        appendData(arr, n);
    }

    void append(T *arr, size_t n)
    {
        appendData(arr, n);
    }

    template <typename Cont>
    void append(Cont &cont)
    {
        typename Cont::iterator it;
        for (it = cont.begin(); it != cont.end(); ++it)
        {
            data.push_back(&(*it));
        }
    }

    void push_back(const T &val)
    {
        data.push_back(val);
    }

    const T &at(const int &i) const
    {
        return *data.at(i);
    }

    size_t size() const
    {
        return data.size();
    }

    const T &operator[](const int &i) const
    {
        return *data.at(i);
    }

    T &operator[](const int &i)
    {
        return *data.at(i);
    }

    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
        array_appender<T>* parent;
        int index;
    public:
        iterator(array_appender<T>* parent, int index) : parent(parent), index(index) {}

        bool operator==(const iterator& it) const {
            return parent == it.parent && index == it.index;
        }

        bool operator!=(const iterator& it) const {
            return !(*this == it);
        }

        iterator& operator++() {
            ++index;
            return *this;
        }

        T& operator*() {
            return (*parent)[index];
        }

        int operator-(const iterator& it) const {
            return index - it.index;
        }
    };

    iterator begin() {
        return iterator(this, 0);
    }

    iterator end() {
        return iterator(this, size());
    }
};

#endif