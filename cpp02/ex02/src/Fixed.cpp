/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:31:07 by javi              #+#    #+#             */
/*   Updated: 2024/04/07 21:31:11 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//******** Constructors and destructor **********
Fixed::Fixed(void): _number_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& original)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = original;
}

Fixed::Fixed(const int from_integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->_number_value = from_integer << this->_fractional_bits;
}

Fixed::Fixed(const float from_float)
{
    std::cout << "Float constructor called" << std::endl;
    this->_number_value = (int)(roundf(from_float * (1 << this->_fractional_bits)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//******** Asignation Overload **********
Fixed& Fixed::operator =(const Fixed& original)
{
    std::cout << "Copy assaigment operator called" << std::endl;
    if (this != &original)
        this->setRawBits(original.getRawBits());
    return *this;
}

//******** Member Functions **********
int Fixed::getRawBits(void) const
{
   // std::cout << "getRawBits function called" << std::endl;
    return this->_number_value;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits function called" << std::endl;
    this->_number_value = raw;
}

float Fixed::toFloat(void) const
{
   return ((float)(this->_number_value / (float)(1 << this->_fractional_bits)));
}

int Fixed::toInt(void) const
{
   return (this->_number_value >> this->_fractional_bits);
}

//******** Outstream Overload **********
std::ostream& operator<<(std::ostream& ost, const Fixed& fixed)
{
    ost << fixed.toFloat();
    return ost;
}

//******** Comparison operators overload **********
bool Fixed::operator==(const Fixed& otherfix) const
{
    return (this->_number_value == otherfix._number_value);
}

bool Fixed::operator!=(const Fixed& otherfix) const
{
    return !(*this == otherfix);
}

bool Fixed::operator>=(const Fixed& otherfix) const
{
    return (this->_number_value >= otherfix._number_value);
}

bool Fixed::operator<=(const Fixed& otherfix) const
{
    return (this->_number_value <= otherfix._number_value);
}

bool Fixed::operator>(const Fixed& otherfix) const
{
    return (this->_number_value > otherfix._number_value);
}

bool Fixed::operator<(const Fixed& otherfix) const
{
    return (this->_number_value < otherfix._number_value);
}

//******** Arithmetic operators overload **********
Fixed Fixed::operator+(const Fixed& otherfix) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + otherfix.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& otherfix) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - otherfix.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& otherfix) const
{
    return (Fixed(this->toFloat() * otherfix.toFloat()));
}

Fixed Fixed::operator/(const Fixed& otherfix) const
{
    if (otherfix.getRawBits() == 0)
        std::cout << "Error. Division by Zero." << std::endl;
    return (Fixed(this->toFloat() / otherfix.toFloat()));
}

//******** Inc/Decrement Prefix operators overload **********
Fixed& Fixed::operator++(void)
{
    this->_number_value++;
    return *this;
}

Fixed& Fixed::operator--(void)
{
    this->_number_value--;
    return *this;
}

//******** Inc/Decrement Sufix operators overload **********
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return tmp;
}

//******** Min y Max **********
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return ((a < b)? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return ((a < b)? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return ((a > b)? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return ((a > b)? a : b);
}
