#include <iostream>

enum class color {red, green, blue};

std::string print_color(color c)
{
	std::string s = "The color is ";
	switch (c)
	{
		case color::red:
			s += "red";
			break;
		break;
		case color::green:
			s += "green";
			break;

		case color::blue:
			s += "blue";
			break;
	}	
	return s;
}

int main()
{
	std::cout<<static_cast<int>(color::red)<<"\t"<<static_cast<int>(color::blue)<<std::endl;
	color c = color::red;
	std::cout<<print_color(c)<<std::endl;
	// if (c == 7) {} // enum class, nem konvertalodik automatikusan intre, forditasi hiba
	return 0;
}