#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v;
	int i;
	while(std::cin>>i)
	{
		v.push_back(i);
	}
	if(v.size() == 0)
		return;
	std::cout<<v[0];
	for(int j = 1; j < v.size(); ++j)
		std::cout << " " << v[j];
	std::cout<<std::endl;
	std::sort(v.begin(), v.end());
	std::cout<<v[0];
	for(int j = 1; j < v.size(); ++j)
		std::cout << " " << v[j];
	std::cout<<std::endl;
}