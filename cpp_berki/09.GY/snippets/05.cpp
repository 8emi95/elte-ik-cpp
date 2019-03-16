#include <iostream>

int main() {
	char str[] = "hallo";
	std::cout << str[1] << std::endl;
	std::cout << (str + 1) << std::endl;
	std::cout << (str[1] + 1) << std::endl;
	std::cout << (str[1] = 'e') << std::endl;
}