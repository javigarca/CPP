/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:15:33 by javi              #+#    #+#             */
/*   Updated: 2024/04/09 10:15:35 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
    public:
        Point();
        Point(float a, float b);
        Point(const Point& p);
        ~Point();

        Point& operator=(const Point& p);
        bool operator==(const Point& p) const;
        bool operator!=(const Point& p) const;

        const Fixed& getx(void) const;
        const Fixed& gety(void) const;
        void setx(Fixed const a);
        void sety(Fixed const b);

    private:
        Fixed x;
        Fixed y;

};

#endif
