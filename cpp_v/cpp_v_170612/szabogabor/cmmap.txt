#ifndef cmmap_h
#define cmmap_h

#include <map>

template <typename T,typename K>

class convenient_multimap: public std::multimap<T,K>{
public:

    void add(T t,K k){
        this->insert(std::pair<T,K>(t,k));
    }
    void update_key(T key0, T key1){
        std::multimap<T,K> temp;
        for(typename std::multimap<T,K>::iterator it = this->begin();it != this->end();){
            if(it->first == key0){
                temp.insert(std::pair<T,K>(key1,it->second));
                typename std::multimap<T,K>::iterator save = it;
                ++save;
                this->erase(it);
                it=save;
            }
            else{
                ++it;
            }
        }
        for(typename std::multimap<T,K>::iterator it2 = temp.begin();it2 != temp.end();++it2){
            add(it2->first,it2->second);
        }
    }
    K front() const{
            return this->begin()->second;
    }
};
#endif // cmmap_h
