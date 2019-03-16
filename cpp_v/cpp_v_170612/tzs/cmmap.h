#ifndef CMMAP_H
#define CMMAP_H
#include <map>

template<class Key, class Value>
class convenient_multimap : public std::multimap<Key,Value> {
	typedef std::multimap<Key,Value> base;
	public:
		void add(Key k, Value v){
			base::insert(std::pair<Key,Value>(k,v));
		}
		void update_key(Key oldk, Key newk) {
			typename base::iterator it = base::find(oldk);
			int count = base::count(oldk);
			for(int i = 0; i < count; i++){
				add(newk,it->second);
				it++;
			}
			base::erase(oldk);
		}
		Key front() const {
			return base::begin()->second;
		}
};



/*
template<typename key, typename value>
class convenient_multimap {
	std::multimap<key, value> container;
	
	public:
		typedef typename std::multimap<key, value>::const_iterator const_iterator;
		typedef typename std::multimap<key, value>::iterator iterator;
		
		void add(key k, value v) {
			container.insert(std::make_pair(k,v));
		}
		
		void update_key(const key& oldKey, const key newKey) const{
					
			/*if(!container.key_comp()(oldKey,newKey) && !container.key_comp()(newKey,oldKey))
			{return;}
			std::multimap<key, value>::iterator begin(container.find(oldKey));
			for(;;){
				if(begin != container.end()){
					container.insert(std::multimap<key, value>::value_type(newKey, begin->second));
					container.erase(begin);
					begin = container.find(oldKey);
				}
				else{
					return;
				}
			}
			for(typename std::multimap<key, value>::iterator it = container.find(oldKey); it != container.end();) {
				add(newKey, it->second);
				container.erase(it);
				it=container.find(oldKey);
			}
			
			/*for(typename std::multimap<key, value>::iterator it = container.begin; it != container.end();) {
				if(it-> first == oldKey) {
					add(newKey, it-> second);
					container.erase(it);
					it++;
				}
			}*/
			
			/*iterator it=container.find(oldKey);
			while(it != container.end()) {
				container.insert(std::make_pair(newKey, oldKey->second));
				container.erase(it);
				it=container.find(oldKey);
			}
			
		}
		int size() const {return container.size();}
		key front() const {}
		int count(key k) const {return container.count(k);}
		const_iterator begin() {return container.begin();}
		//iterator begin() {return container.begin();}
};

*/





#endif