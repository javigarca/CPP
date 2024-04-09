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

#include <iostream>
#include "Fixed.hpp"

int main(void)

{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

std::cout << "\nMore\n";
std::cout << "-----------------\n";
Fixed c = a;
std::cout << Fixed::min(c, b) << std::endl; // 0.0078125
std::cout << b / Fixed(2) << std::endl; // 5.05078
std::cout << b / Fixed() << std::endl; // 5.05078
Fixed z =( b / Fixed(2));
std::cout << b + Fixed(-3.14f) << std::endl; // 6.96094
std::cout << b - Fixed(18) << std::endl; // -7.89844
std::cout << z * Fixed(2) << std::endl; 
std::cout << (c != a) << std::endl; // 0
std::cout << (c == a) << std::endl; // 1
std::cout << z << std::endl;
std::cout << --z << std::endl;
std::cout << z << std::endl;
std::cout << z-- << std::endl;
std::cout << z << std::endl;
return 0;
}
