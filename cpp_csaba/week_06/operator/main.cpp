#include <iostream>

class Rational
{
  public:
    enum Exceptions
    {
        ZERO_DENOMINATOR
    };

    Rational(int x = 0, int y = 1) : numerator(x), denominator(y)
    {
        if (0 == denominator)
        {
            throw ZERO_DENOMINATOR;
        }
        std::cout << "constructor" << std::endl;        
    }

    Rational(const Rational &r) : numerator(r.numerator), denominator(r.denominator)
    {
        std::cout << "cpy constructor" << std::endl;
    }

    friend Rational operator*(const Rational &r1, const Rational &r2);

    Rational &operator*=(const Rational &other)
    {
        this->numerator *= other.numerator;
        this->denominator *= other.denominator;
        return *this;
    }

    operator int()
    {
        return numerator / denominator;
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    Rational getThis()
    {
        std::cout << "getThis" << std::endl;        
        return *this;
    }

    Rational &getThisR()
    {
        std::cout << "getThisR" << std::endl;        
        return *this;
    }

    Rational *getThisP()
    {
        std::cout << "getThisP" << std::endl;        
        return this;
    }

  private:
    int numerator;
    int denominator;
};

Rational operator*(const Rational &r1, const Rational &r2)
{
    return Rational(r1.numerator * r2.numerator, r1.denominator * r2.denominator);
}

std::ostream &operator<<(std::ostream &os, const Rational &r)
{
    os << r.getNumerator() << "/" << r.getDenominator();
}

struct Foo
{
    int x, y;
    Foo(int i) : y(i), x(y++) {}
};

int main()
{

    Rational rational(1, 2), other(3, 4);

    other *= rational;

    std::cout << other << std::endl;

    Rational another(4, 2);
    std::cout << another << std::endl;
    std::cout << other * another << std::endl;
    // std::cout << 10 * another << std::endl; //ambigious overload

    Foo f(10);
    std::cout << f.x << std::endl;

    another.getThis();
    another.getThisR();
    another.getThisP();

    return 0;
}