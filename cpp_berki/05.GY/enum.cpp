#include <iostream>

enum color {red, green, blue};

std::string print_color(color c)
{
	std::string s = "The color is ";
	switch (c)
	{
		case red:
			s += "red";
			break;
		break;
		case green:
			s += "green";
			break;

		case blue:
			s += "blue";
			break;
	}	
	return s;
}

int main()
{
	std::cout<<red<<"\t"<<blue<<std::endl;
	color c = red;
	std::cout<<print_color(c)<<std::endl;
	if (c == 7) {} // colornak nincs 7-es értékű eleme, mégis fordul
	return 0;
}