#include <iostream>

class Vehicle {
public:
    int a = 1;
    virtual void getPassengers();
protected:
    int b = 2;
    virtual void getInheritance(){
        std::cout << "asd" << std::endl;
    }
private:
    int c = 3;
    void getSecret() {
        std::cout << "SecretComponent :D" << std::endl;
    }
};

class Car : public Vehicle {
public:
    virtual void  getPassengers() {
        this->getInheritance();
        std::cout << "Oops, its not fully abstract!" << std::endl;
    }
};

class Audi : public Car{
public:
    int a = 4;
    void getPassengers() {
        std::cout << "5 if not so small XD" << std::endl;
    };
protected:
    int b = 5;
    void getInheritance(){
        std::cout << "asd" << std::endl;
    }
private:
    int c = 6;
    void getSecret() {
        std::cout << "SecretComponent :D" << std::endl;
    }
};

int main() {
    Car *car;
    Audi audi;
//    car->getPassengers();
    audi.getPassengers();

    return 0;
}