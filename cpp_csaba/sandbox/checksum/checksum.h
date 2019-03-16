#ifndef CSUM_H
#define CSUM_H

#include <iostream>
#include <set>
#include <algorithm>

template <typename Cont, typename Unary, typename T = typename Cont::value_type, typename Binary = std::plus<int> >
class checksum
{
  private:
    int ch;
    Unary uf;
    Binary bf;
    Cont *cont;
    int mp;

    int calculate_checksum() const
    {
        int checksum = mp;
        typename Cont::const_iterator it;
        for (it = cont->begin(); it != cont->end(); ++it)
        {
            checksum = bf(checksum, uf(*it));
        }
        return checksum;
    }

  public:
    checksum(Cont &cont, int mp = 0) : cont(&cont), mp(mp)
    {
        ch = calculate_checksum();
    }

    int get_checksum() const
    {
        return calculate_checksum();
    }

    bool validate_checksum() const
    {
        return ch == calculate_checksum();
    }

    void update_checksum()
    {
        ch = calculate_checksum();
    }
};

#endif