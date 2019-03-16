//
// Created by Csaba Hete on 2016.10.10..
//

#ifndef GYAK4_CIRCLE_H
#define GYAK4_CIRCLE_H

class Circle
{
  private:
    int x, y, r;

  public:
    Circle();
    Circle(const Circle &);
    ~Circle();
    int getR();
    int getRconst() const;
};

#endif //GYAK4_CIRCLE_H
