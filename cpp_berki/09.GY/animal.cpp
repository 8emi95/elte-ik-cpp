#include <iostream>

class Animal
{
private:
	std::string _name;
	int _legs;
public:
	Animal(std::string name, int legs) : _name(name), _legs(legs) {
		std::cout<<"Animal() "<<_name<<std::endl;
	}
	~Animal() {
		std::cout<<"~Animal() "<<_name<<std::endl;
	}
	void speak() const { std::cout<<"nyekk"<<std::endl; }
	int getLegs() const { return _legs; }
	std::string getName() const { return _name; }
};

int main() 
{
	Animal riksa("Riksa", 4);
	riksa.speak();
}
