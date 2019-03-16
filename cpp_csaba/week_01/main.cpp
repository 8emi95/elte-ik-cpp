#include <iostream>

int main()
{
    // int i = 0, j = 0;
    // std::cout << "i: " << i << ", j: " << j << std::endl;
    // while (++i == 0 && ++j == 0)
    // {
    //     std::cout << "i: " << i << ", j: " << j << std::endl;
    // }

    //    double d;
    //    while (d != 1.0 && d < 1.1) {
    //        d += 0.1;
    //        std::cout << d << " " << std::endl;
    //    }

    std::cout << "size of bool: " << sizeof(bool) << std::endl; // size of bool: 1
    std::cout << "size of char: " << sizeof(char) << std::endl; // size of char: 1
    std::cout << "size of short: " << sizeof(short) << std::endl; // size of short: 2
    std::cout << "size of int: " << sizeof(int) << std::endl; // size of int: 4
    std::cout << "size of unsigned int: " << sizeof(unsigned int) << std::endl; // s
    std::cout << "size of long: " << sizeof(long) << std::endl; // size of long: 4
    std::cout << "size of unsigned long: " << sizeof(unsigned long) << std::endl; // size of unsigned long: 4
    std::cout << "size of long long: " << sizeof(long long) << std::endl; // size of long long: 8
    std::cout << "size of unsigned long long: " << sizeof(unsigned long long) << std::endl; // size of unsigned long long: 8
    std::cout << "size of float: " << sizeof(float) << std::endl; // size of float: 4
    std::cout << "size of double: " << sizeof(double) << std::endl; // size of double: 4
    std::cout << "size of long double: " << sizeof(long double) << std::endl; // size of long double: 12

    std::string h = "hello";
    for (int i = 0; i < h.length(); ++i)
    {
        // std::cout << "h[i]=" << h[i] << " i=" << i << "; "; // h[i]=h i=0; h[i]=e i=1; h[i]=l i=2; h[i]=l i=3; h[i]=o i=4;
        std::cout << h[i]; // hello
    }
    std::cout << std::endl;

    std::string hi = "hel\0lo";

    for (int i = 0; i < hi.length(); ++i)
    {
        // std::cout << "h[i]=" << h[i] << " i=" << i << "; "; // h[i]=h i=0; h[i]=e i=1; h[i]=l i=2;
        std::cout << h[i]; // hel
    }
    std::cout << std::endl;

    std::cout << "size of text hello: " << sizeof("hello") << std::endl; // size of text hello: 6
    std::cout << "size of endchar: " << sizeof('\0') << std::endl; // size of endchar: 1
    std::cout << "size of text hel'endchar'lo: " << sizeof("hel\0lo") << std::endl; // size of text hel'endchar'lo: 7

    char t[10] = "hello"; // t="hello" nem működik
    std::cout << "t[2]: " << t[2] << std::endl; // l

    char chArr1[] = "hello char array";
    const char *chPointr = "hello char pointer";

    int intArr[] = {1, 2, 3};

    std::cout << "chArr1: " << chArr1 << std::endl; // hello char array
    //whole string
    std::cout << "chPointr: " << chPointr << std::endl; // hello char pointer
    //-||-
    std::cout << "intArr: " << intArr << std::endl; // 0x60feb0
    // ptr of first element

    int i = 3;
    int *p = &i;
    std::cout << "p: " << p << std::endl; // 0x60feac
    std::cout << "*p: " << *p << std::endl; // 3

    int b = 5;
    int &r = b;

    std::cout << "b: " << b << std::endl; // b: 5
    std::cout << "r: " << r << std::endl; // r: 5
    b++;
    std::cout << "b: " << b << std::endl; // b: 6
    std::cout << "r: " << r << std::endl; // r: 6

    std::cin.get();

    return 0;
}