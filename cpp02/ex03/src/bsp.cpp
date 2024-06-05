/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:38:04 by javi              #+#    #+#             */
/*   Updated: 2024/04/09 13:38:06 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

Fixed area_tri(Point const a, Point const b, Point const c)
{
    Fixed area;

    area = (a.getx() * (b.gety() - c.gety())) + (b.getx() * (c.gety() - a.gety())) + (c.getx() * (a.gety() - b.gety()));
    area = area / Fixed(2);
    if (area < Fixed(0))
        area = area * -1;
    return area; 
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if ((point == a) || (point == b) || (point == c))
    {
        std::cout << "The point is a vertex, so is not considered inside the area of the triangle." << std::endl;
        return false;
    }
    Fixed total = area_tri(a, b, c);
    if (total == Fixed(0))
    {
       std::cout << "The vertices do not form a triangle." << std::endl;
       return false;
    }
    Fixed areaABP = area_tri(a, b, point);
    Fixed areaACP = area_tri(a, c, point);
    Fixed areaBCP = area_tri(b, c, point);
    if ((areaABP == Fixed(0)) || (areaACP == Fixed(0)) || (areaBCP == Fixed(0)))
    {
       std::cout << "The point is in the borders of the triangle, so is not considered inside the area of the triangle." << std::endl;
       return false;
    }
    if (total == areaABP + areaACP + areaBCP)
        return true;
    return false;
}
