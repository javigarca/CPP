#include "Complex.hpp"

Complex::Complex() : _real(0), _imag(0) {}

Complex::Complex(double real, double imag) : _real(real), _imag(imag) {}

Complex::Complex(const Complex& other) : _real(other._real), _imag(other._imag) {}

Complex::~Complex() {}

Complex& Complex::operator=(const Complex& other)
{
    if (this != &other)
    {
        _real = other._real;
        _imag = other._imag;
    }
    return *this;
}

double Complex::getReal() const
{
    return _real;
}

double Complex::getImag() const
{
    return _imag;
}

void Complex::setReal(double real)
{
    _real = real;
}

void Complex::setImag(double imag)
{
    _imag = imag;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c._real << " + " << c._imag << "i";
    return os;
}