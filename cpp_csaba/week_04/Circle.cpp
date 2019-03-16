//
// Created by Csaba Hete on 2016.10.10..
//
#include <iostream>
#include "Circle.h"

int Circle::getR()
{
    return r;
}

int Circle::getRconst() const
{
    return r;
}

Circle::Circle()
{
    std::cout << "constructor" << std::endl;
}
Circle::Circle(const Circle &other) : x(other.x), y(other.y), r(other.r)
{
    std::cout << "copy constructor" << std::endl;
}
Circle::~Circle()
{
    std::cout << "destructor" << std::endl;
}
