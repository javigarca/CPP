/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:30:56 by javi              #+#    #+#             */
/*   Updated: 2024/04/07 21:30:59 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"

int	main()
{
	Point	A(0, 0);
	Point	B(3, 0);
	Point	C(1.5f, 3);
    Point   D(2, 0);
	Point	P0(1.5f, 1); // inside
	Point	P1(1.5f, 2); // inside
	Point	P2(1.5f, 3); // vertex
    Point	P3(2, 0); // inline
    Point	P4(3.1f, 5); // outside

	std::cout << "Has to be inside:\n";
	if (bsp(A, B, C, P0) == true)
		std::cout << "The point is inside the triangle!\n";
	else
		std::cout << "The point is outside the triangle!\n";


	std::cout << "Has to be inside:\n";
	if (bsp(A, B, C, P1) == true)
		std::cout << "The point is inside the triangle!\n";
	else
		std::cout << "The point is outside the triangle!\n";

	std::cout << "Has to be vertex:\n";
	if (bsp(A, B, C, P2) == true)
		std::cout << "The point is inside the triangle!\n";
	else
		std::cout << "The point is outside the triangle!\n";
    
    std::cout << "Has to be inline:\n";
	if (bsp(A, B, C, P3) == true)
		std::cout << "The point is inside the triangle!\n";
	else
		std::cout << "The point is outside the triangle!\n";
    
    std::cout << "Has to be outside:\n";
	if (bsp(A, B, C, P4) == true)
		std::cout << "The point is inside the triangle!\n";
	else
		std::cout << "The point is outside the triangle!\n";
    
    std::cout << "Not triangle:\n";
	if (bsp(A, B, D, P1) == true)
		std::cout << "The point is inside the triangle!\n";
	else
		std::cout << "The point is outside the triangle!\n";

	return (0);
}
