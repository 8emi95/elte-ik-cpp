#ifndef CHECKSUM_H
#define CHECKSUM_H
#include <functional> //std::plus

template <typename Container, typename Unary, typename T = typename Container::value_type, typename Binary = std::plus<int> >
class checksum
{
    Container* _cont;
    int _multiplyer;
    int _checksum;
    Unary _function;
    Binary _secondFunction;
    typedef typename Container::const_iterator _iterator;

    int _calculate_chechsum() const
    {
        int result = _multiplyer;
        for (_iterator it = _cont->begin(); it != _cont->end(); it++)
        {
            result = _secondFunction(result, _function(*it));
        }
        return result;
    }
public:
    checksum(Container &cont, int mul = 0) : _cont(&cont), _multiplyer(mul) { _checksum = _calculate_chechsum(); }

    int get_checksum() const { return _checksum; };

    bool validate_checksum() const
    {
        if(_calculate_chechsum() == _checksum)  return true;
        else                                    return false;
    }

    void update_checksum() { _checksum = _calculate_chechsum(); }
};

#endif