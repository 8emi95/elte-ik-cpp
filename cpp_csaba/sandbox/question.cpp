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
    audi.getPassengers();
    //Audi *audi = new Audi(); // undefined reference to `vtable for Vehicle'
    return 0;
}




#include <iostream>

class Rational {
public:
    enum Exceptions {
        ZERO_DENOMINATOR
    };

    Rational(int x = 0, int y = 1) : numerator(x), denominator(y) {
        if (0 == denominator) {
            throw ZERO_DENOMINATOR;
        }
    }

    Rational &operator*=(const Rational &other) {
        this->numerator *= other.numerator;
        this->denominator *= other.denominator;
    };

    int getNumerator() {
        return  numerator;
    }

    int getDenominator() {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {

    Rational rational(1, 2), other(3, 4);

    other *= rational;

    std::cout << other.getNumerator() << std::endl;
    std::cout << other.getDenominator() << std::endl; //működik, bár nincs visszatérési értéke az operatornak ! ?

    return 0;
}