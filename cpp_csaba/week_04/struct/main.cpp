#include <iostream>

struct person
{
    const char *name;
    int age;
    // int arr[]; //ISO C++ forbids zero-size array

    // person()
    // {
    //     std::cout << "Struct constructor" << std::endl;
    // }
    // ~person()
    // {
    //     std::cout << "Struct destructor" << std::endl;
    // }
};
// } globalPerson; //will create a global variable

struct circle
{
    struct  //anonym struct
    {
        int x, y;
    } center;
    int radius;
};

int main()
{
    // std::cout << "globalPerson name: " << globalPerson.name << std::endl;
    // std::cout << "globalPerson age: " << globalPerson.age << std::endl;
    
    person Pityu = {"Pityu", 30};
    std::cout << "person name: " << Pityu.name << std::endl;
    std::cout << "person age: " << Pityu.age << std::endl;

    person *personPointer = &Pityu;
    std::cout << "person name through &pointer: " << Pityu.name << std::endl;
    std::cout << "person age through pointer: " << Pityu.age << std::endl;

    person ClonePityu = Pityu;
    std::cout << "clone name: " << ClonePityu.name << std::endl;
    std::cout << "clone age: " << ClonePityu.age << std::endl;

    Pityu.name = "asdf";
    std::cout << "person name: " << Pityu.name << std::endl;
    std::cout << "person age: " << Pityu.age << std::endl;
    std::cout << "person name through &pointer: " << Pityu.name << std::endl;
    std::cout << "person age through pointer: " << Pityu.age << std::endl;
    std::cout << "clone name: " << ClonePityu.name << std::endl;
    std::cout << "clone age: " << ClonePityu.age << std::endl;
}