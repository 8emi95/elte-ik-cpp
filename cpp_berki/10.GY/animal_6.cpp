#include <iostream>

class Animal
{
protected:
	std::string _name;
	int _legs;
public:
	Animal(std::string name, int legs) : _name(name), _legs(legs) {
		std::cout<<_name<<" Animal()"<<std::endl; }
	virtual ~Animal() {
		std::cout<<_name<<" ~Animal()"<<std::endl; }
	virtual void speak() const = 0;
	int getLegs() const { return _legs; }
	std::string getName() const { return _name; }
};

class Dog : public Animal {
public:
	Dog(std::string name) : Animal(name, 4) { 
		std::cout<<_name<<" Dog()"<<std::endl; }
	void speak() const { std::cout<<_name<<" bark"<<std::endl; }
	virtual ~Dog() { std::cout<<_name<<" ~Dog()"<<std::endl; }
};

class Frog : public Animal {
public:
	Frog(std::string name) : Animal(name, 2) {}
	void speak() const { std::cout<<_name<<" ribbit"<<std::endl; }
	virtual ~Frog() { std::cout<<_name<<" ~Frog()"<<std::endl; }
};

class Husky : public Dog {
public:
	Husky(std::string name) : Dog(name) {
		std::cout<<_name<<" Husky()"<<std::endl; }
	void shakePaw() { std::cout<<_name<<" shakes paw"<<std::endl; }
	~Husky() { std::cout<<_name<<" ~Husky()"<<std::endl; }
};

int main() 
{
	Dog buksi("Buksi");
	Animal* fifi = new Husky("Fifi");
	fifi->speak();
	static_cast<Husky*>(fifi)->shakePaw();	
	delete fifi;
}
