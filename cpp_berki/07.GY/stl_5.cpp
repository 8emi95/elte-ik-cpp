#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> v(std::istream_iterator<int>(std::cin),
		std::istream_iterator<int>() );
	std::copy(v.begin(), v.end(), 
		std::ostream_iterator<int>(std::cout, " ") );
	std::endl(std::cout);
	std::sort(v.begin(), v.end());
	std::copy(v.begin(), v.end(), 
		std::ostream_iterator<int>(std::cout, " ") );
	std::endl(std::cout);
}