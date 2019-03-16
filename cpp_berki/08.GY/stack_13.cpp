#include "stack.h"
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
	stack<int> s;
	s.push(5).push(3).push(2);
	std::cout<<s<<std::endl;
	stack<std::string> t;
	std::cin>>t;
	std::cout<<t<<std::endl;
	typename stack<int>::iterator it = std::find(s.begin(), s.end(), 3);
	if(it != s.end())
		std::cout<<*it<<std::endl;
}
