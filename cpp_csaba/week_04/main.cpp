#include <iostream>
#include "Circle.h"

struct Kor
{
    Kor() : x(0), y(0), r(0)
    {
        std::cout << "Struct constructor" << std::endl;
    }
    ~Kor()
    {
        std::cout << "Struct destructor" << std::endl;
    }
    int x, y;
    int r;
};

void f(const char *c);
void f(int i);
void f(double i);
//double f(double i); //Visszatérési érték szerint nem lehet túlterhelni
void getR(const Circle &circle);
void ref(int &r);
void setRTo5(Kor &circle);
void getR(Kor &circle);
void getRConstKor(const Kor &circle);

int globalInt;
static int globaStaticInt;

int main()
{
    setlocale(LC_ALL, "Hun");
    int i;
    int *pInt = &i;
    void *pVoid = &i;

    std::cout << "globalInt: " << globalInt << std::endl;
    std::cout << "globalStaticInt: " << globaStaticInt << std::endl;    

    const char *c = "hello";
    f(c);

    std::string hello = "hello";
    std::string blah = "blah";
    //    std::cout<<&hello<<std::endl;
    //    std::cout<<&blah<<std::endl;
    std::cout << (hello < blah ? "hello < blah" : "hello > blah") << std::endl;

    int *j = new int(3); //heap-en jön létre
    std::cout << (*j == 3 ? "*j == 3" : "*j != 3") << std::endl;
    std::cout << j << " referenced value: " << *j << std::endl;
    *j = 5;
    std::cout << j << " referenced value: " << *j << std::endl;
    delete j;
    std::cout << j << " referenced value: " << *j << std::endl;

    f(3);
    f(3.0);

    ref(i);

    Kor circleAsStruct;
    circleAsStruct.x = 1;
    circleAsStruct.y = 1;
    circleAsStruct.r = 3;
    const Kor constKor = circleAsStruct; //lemásolódik az objektum

    //    setRTo5(circleAsStruct);
    getRConstKor(circleAsStruct);
    getR(circleAsStruct);
    delete &constKor;

    Circle circleAsClass;
    const Circle constCircle = circleAsClass;
    delete new Circle();

    std::cout << circleAsClass.getRconst() << std::endl; //nem konstans objektumon meghivható
    std::cout << circleAsClass.getR() << std::endl;

    std::cout << constCircle.getRconst() << std::endl; // konstans objektumon meghivható
    //    std::cout << constCircle.getR() << std::endl; //konstans objektumon nem hívható meg nem konstans metódus
}

void f(const char *c)
{
    std::cout << c << std::endl;
}

void f(int i)
{
    std::cout << "overloaded f with int param: " << i << std::endl;
}

void f(double i)
{
    std::cout << "overloaded f with double param: " << i << std::endl;
}

//double f(double i) { //Visszatérési érték szerint nem lehet túlterhelni
//    std::cout<< "overloaded f with double param: "<< i << std::endl;
//    return i;
//}

void getR(const Circle &circle)
{
    circle.getRconst();
}

void ref(int &r)
{
    std::cout << "r: " << r << std::endl;
    r = 5;
}

void setRTo5(Kor &circle)
{
    std::cout << "current r: " << circle.r << std::endl;
    circle.r = 5;
    std::cout << "r after set to 5: " << circle.r << std::endl;
}

void getR(Kor &circle)
{
    std::cout << "current r: " << circle.r << std::endl;
}

void getRConstKor(const Kor &circle)
{
    std::cout << "current r: " << circle.r << std::endl;
}