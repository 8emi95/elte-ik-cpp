#include <iostream>

char convert(char ch)
{
	static const char from[] = {'a','w','f'};
	static const char to[] = {'b','c','z'};
	for(size_t i = 0; i < sizeof(from)/sizeof(from[0]); ++i)
	{
		if (ch == from[i])
			return to[i];
	}
	return ch;
}
	
int main()
{
	std::string st = "Az aranyos kiwi falatozik.";
	for(size_t i = 0; i < st.size(); ++i)
	{
		std::cout<<convert(st[i]);
	}
	return 0;
}