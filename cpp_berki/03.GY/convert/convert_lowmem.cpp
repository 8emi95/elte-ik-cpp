#include <iostream>

char convert(char ch)
{
	switch(ch)
	{
		case 'a':
			return 'b';
		case 'w':
			return 'c';
		case 'f':
			return 'z';
		default:
			return ch;
	}
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