#include <iostream>
#include <typeinfo>

class GrandGrandParent
{
  public:
    int age;

    void getName()
    {
        std::cout << "GrandGrandparent" << std::endl;
    }

    GrandGrandParent() : age(80)
    {
        std::cout << "Constructor of GrandGrandParent" << std::endl;
    }
};

class GrandParent : public GrandGrandParent
{
  public:
    //    GrandGrandParent grandGrandParent;
    int age;

    void getName()
    {
        std::cout << "GrandParent" << std::endl;
    }

    GrandParent() : age(60)
    {
        std::cout << "Constructor of GrandParent" << std::endl;
    }
};

class Parent : public GrandParent
{
  public:
    int age;

    void getName()
    {
        std::cout << "Parent" << std::endl;
    }

    Parent() : age(40)
    {
        std::cout << "Constructor of Parent" << std::endl;
    }
};

class Child : public Parent
{
  public:
    //    Parent parent;
     int age;

    void getName()
    {
        std::cout << "Child" << std::endl;
    }

    Child(int age = 20) : age(age)
    {
        std::cout << "Constructor of Child" << std::endl;
    }
};

///** Ambiguous*/
//class Father: public Parent, GrandParent {
//
//};

int main()
{
    /** Going up, run all the constructors from top to down*/
    Child child;
    std::cout << typeid(child).name() << std::endl;
    Child wtf(); //ezmiez????
    std::cout << typeid(wtf).name() << std::endl;

    /** Constructor of Parent GrandParent, GrandGrandParent */
    Parent parent;                        // looking through Parent, all methods and attributes
    std::cout << parent.age << std::endl; //if not in Parent, then going up

    /** Going up, run all the constructors */
    Parent *parentPointer; //pointer only, no constructor
    child.getName();       //Child
    parentPointer = &child;
    (*parentPointer).getName(); //Parent, if not implemented, going up to nearest. If not implemented in parents, Compiler error
    parentPointer->getName();   //Parent
    std::cout << parentPointer->age << std::endl; //Parent
    std::cout << (*parentPointer).age << std::endl; //Parent

    //    /** Ambiguity problem*/
    //    Father father;
    //    father.getName(); // compiler cannot resolve to method getName()

    return 0;
}