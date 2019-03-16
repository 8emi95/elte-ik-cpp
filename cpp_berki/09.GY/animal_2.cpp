#include <iostream>

class Animal
{
protected:
	std::string _name;
	int _legs;
public:
	Animal(std::string name, int legs) : _name(name), _legs(legs) {
		std::cout<<_name<<" Animal()"<<std::endl;
	}
	~Animal() {
		std::cout<<_name<<" ~Animal()"<<std::endl;
	}
	void speak() const { std::cout<<_name<<" nyekk"<<std::endl; }
	int getLegs() const { return _legs; }
	std::string getName() const { return _name; }
};

class Dog : public Animal
{
public:
	Dog(std::string name) : Animal(name, 4) { //: _name(name), _legs(4) { 
		std::cout<<_name<<" Dog()"<<std::endl;
	}
	void speak() const { std::cout<<_name<<" bark"<<std::endl; }
	~Dog() {
		std::cout<<_name<<" ~Dog()"<<std::endl;
	}
};

int main() 
{
	Animal riksa("Riksa", 4);
	riksa.speak();
	Dog buksi("Buksi");
	buksi.speak();
	Animal* fifi = new Dog("Fifi");
	dynamic_cast<Dog*>(fifi)->speak();
}
