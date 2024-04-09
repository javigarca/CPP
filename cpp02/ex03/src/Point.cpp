/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:15:28 by javi              #+#    #+#             */
/*   Updated: 2024/04/09 10:15:31 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(float a, float b) : x(a), y(b)
{}

Point::Point(const Point& p)
{
   *this = p;
}

Point::~Point()
{}

Point& Point::operator=(const Point& p)
{
    if (this != &p)
    {
        this->setx(p.getx());
        this->sety(p.gety());
    }
    return *this;
}

bool Point::operator==(const Point& p) const
{
    if ((this->getx() == p.getx()) && (this->gety() == p.gety()))
        return true;
    return false;
}

bool Point::operator!=(const Point& p) const
{
    return !(*this == p);
}

const Fixed& Point::getx(void) const
{
    return this->x;
}

const Fixed& Point::gety(void) const
{
    return this->y;
}

void Point::setx(Fixed const a)
{
    this->x = a;
}

void Point::sety(Fixed const b)
{
    this->y = b;
}
