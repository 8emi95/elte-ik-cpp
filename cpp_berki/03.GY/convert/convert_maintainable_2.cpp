#include <iostream>

struct rule
{
	char from;
	char to;
};

char convert(char ch)
{
	static const rule rules[] = { {'a','b'}, {'w','c'}, {'f','z'}};
	for(size_t i = 0; i < sizeof(rules)/sizeof(rules[0]); ++i)
	{
		if (ch == rules[i].from)
			return rules[i].to;
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