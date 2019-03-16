# ifndef _VIVIEW_H_
# define _VIVIEW_H_
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

template<typename typeOfVector>
class vector_index_view
{
private:
	std::vector<typeOfVector*> view;
	//typename std::vector<typeOfVector*>::iterator whereAreWeAt;
	bool reversed = false;
public:
	static const int npos = -1;
	vector_index_view(std::vector<typeOfVector> &vec) {
		for (unsigned i = 0; i < vec.size(); i++) {
			view.push_back( &(vec.at(i)) );		//referenciák
		}
		//whereAreWeAt = view.begin();
	}

	void swap(const int thisOne, const int thatOne) {
		std::iter_swap(view.begin() + thisOne, view.begin() + thatOne);
	}

	typeOfVector& at(const int index) const{
		return *(view.at(index));
	}

	typeOfVector& operator[](const int index) const {
		return *(view.at(index));
	}

	int index_of(const typeOfVector &param) {
		typename std::vector<typeOfVector>::iterator it;
		std::vector<typeOfVector> findVec;
		for (unsigned i = 0; i < view.size(); i++) {
			findVec.push_back(*(view.at(i)));
		}
		it = find(findVec.begin(), findVec.end(), param);
		if (it != findVec.end()) {
			int index = std::distance(findVec.begin(), it);
			//std::cout << index;
			return index;
		}
		return npos;
	}

	void operator -() {
		if (!reversed) {
			std::reverse(view.begin(), view.end());
			reversed = true;
		}
	}

	void operator +() {
		if(reversed){
			std::reverse(view.begin(), view.end());
			reversed = false;
		}
	}
	/*
	class iterator
	{
	private:
		typename std::vector<typeOfVector*>::iterator p = whereAreWeAt;
	public:
		iterator(typename std::vector<typeOfVector>::iterator _p) : p(_p) {}
		void operator++() {
			p++;
		}
		typename std::vector<typeOfVector>::iterator begin() {
			return view.begin();
		}

		typename std::vector<typeOfVector>::iterator end() {
			return view.end();
		}
	};
	
	typename std::vector<typeOfVector>::iterator begin() {
		return iterator.begin();
	}

	typename std::vector<typeOfVector>::iterator end() {
		return iterator.end();
	}*/

};
# endif