#include <iostream>
#include <vector>

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
	i = v.size() - 1;
	while(i >= 1)
	{
		int j = 0;
		while(j <= i - 1)
		{
			if(v[j] > v[j + 1])
			{
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
			++j;
		}
		--i;
	}
	std::cout<<v[0];
	for(int j = 1; j < v.size(); ++j)
		std::cout << " " << v[j];
	std::cout<<std::endl;
}