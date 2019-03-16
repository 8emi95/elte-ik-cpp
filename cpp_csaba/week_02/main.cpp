#include <iostream>
#include <typeinfo>

int main()
{
    int **ppointer, *pointer, k;
    std::cout << typeid(ppointer).name() << std::endl; //Pi ponter to an integer
    std::cout << typeid(pointer).name() << std::endl;  //Pi ponter to an integer
    std::cout << typeid(k).name() << std::endl;        //i integer

    int arr1[10];
    int arr2[10];
    arr1[10] = 888; //nem definiált viselkedés, itt átcsorog a köv tömbbe
                    //    std::cout<< arr1[10] <<std::endl;

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << arr2[i] << std::endl;
    }

    const int c = 0;

    int i = 5;
    int j = 10;
    const int *p = &i; // p is read-only pointer
    p = &j;
    p = &c;
    //    *p = 8;

    int *const p2 = &i; // p is constant pointer on i
    *p2 = 8;
    // p2 = &c;
    //    p2 = &j;

    const int *const p3 = &i;

    int &x = i;
    const int &cx = i; //read-only reference
    //    ++cx;

    for (size_t i = 0; i < 10; ++i)
    {
        arr1[i] = i+10;
    }
    int *arrp = arr1;
    std::cout << "array pointer dereferencing: " << arrp[0] << std::endl; //pointer to an array dereferences array's first element

    i = 666;
    int *intptr = &i;
    std::cout << "intPointer dereferencing: " << intptr[0] << std::endl; //int pointer dereferencing in an unusual way

    const char text [] = "hello";
    const char * charPtr = text;
    char *w = "text";

    std::cout << "charPtr: " << *charPtr +1 << std::endl; 
    
    return 0;
}