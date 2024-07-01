#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex
{
public:
    Complex();
    Complex(double real, double imag);
    Complex(const Complex& other);
    ~Complex();

    Complex& operator=(const Complex& other);

    double getReal() const;
    double getImag() const;

    void setReal(double real);
    void setImag(double imag);

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

private:
    double _real;
    double _imag;
};

#endif
