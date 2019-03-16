#pragma once

#include <vector>
#include <iterator>
#include <algorithm>

template<typename T, typename Comparator>
class multiset_vector{
    private:
        typename std::vector<T>::iterator beginp;
        typename std::vector<T>::iterator endp;
        Comparator comp;
    public:
        multiset_vector(std::vector<T>& vparam) {
            std::sort(vparam.begin(),vparam.end(),comp);
            beginp = vparam.begin();
            endp = vparam.end();
        }

        int count(const T& param) const {
            int pcount = 0;
            for (typename std::vector<T>::iterator it = beginp; it != endp; it++) {
                if (!(comp(*it,param) || comp(param,*it))) pcount++;
            }
            return pcount;
        }

        void use(std::vector<T>& vparam) {
            std::sort(vparam.begin(),vparam.end(),comp);
            beginp = vparam.begin();
            endp = vparam.end();
        }

        typename std::vector<T>::iterator find(const T& param) const {
            for (typename std::vector<T>::iterator it = beginp; it != endp; it++) {
                if (!(comp(*it,param) || comp(param,*it))) return it;
            }
            return endp;
        }
};
