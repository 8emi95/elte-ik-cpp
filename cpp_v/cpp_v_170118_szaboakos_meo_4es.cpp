#ifndef _listsort_h
#define _listsort_h

#include<list>
#include <algorithm> 

template<class T,class Comp = std::less<T> >
class list_sorter{
	private:
		std::list<T>& cont;
		int counter;
		
	public:
		list_sorter(std::list<T>& li) : cont(li), counter(1){
			cont.sort();
		}
	
	list_sorter<T>& add(std::list<T>& li){
		for(typename std::list<T>::iterator it = li.begin(); it != li.end(); ++it){
			cont.push_back(*it);
		}
		cont.sort();
		li.clear();
		++counter;
		return *this;

/*
add nál használható a merge:
{
t.sort();
list.merge(t);

return *this;
}

*/
	}
	
	list_sorter<T,Comp>& remove(const T& value) {
		Comp comp;
		for(typename std::list<T>::iterator it = cont.begin(); it != cont.end(); ++it){
			
			if(!comp(value,*it) && !comp(*it,value)){
				it = cont.erase(it);
			}
		}
		cont.sort(comp);
		return *this;
	}
	
	int list_count() const{
		return counter;
	}
	
};

#endif