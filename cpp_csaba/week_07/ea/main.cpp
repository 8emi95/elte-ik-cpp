#include <iostream>

void g(int i) {
    i + 0;
    i + 0;
    i + 0;
    std::cout << "i : " << i << std::endl;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
};

int main() {
//    std::cout << "g(3)" << std::endl;
//    g(3);
//    int i = 2;
//    std::cout << "g(i)" << std::endl;
//    g(i);
//    i = 2;
//    std::cout << "g(++i)" << std::endl;
//    g(++i);

    int x = 1;
    int y = 2;
    int *p = &x;
    int *q = &y;
    swap(x, y);
    swap(*p, *q);

    int *pointerArr[5]; //pointerek tömbje
    int (*arrPointer)[5]; //pointer, ami 5 elemű tömbre mutat

    int *func(int); //függvény deklaráció
    int (*funcPointer)(int); //pointer, ami függveényre mutathat, ami 1 intet vár és 1 intet ad vissza
    return 0;
}