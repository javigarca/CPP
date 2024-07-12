/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:02:31 by javi              #+#    #+#             */
/*   Updated: 2024/04/15 12:03:02 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/span.hpp"
#include <iostream>
#include <ctime>

int main()
{
    Span sp(5);
	Span bad;
	
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try 
	{
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		std::cout << "Errors with the Span bad Longest: " << bad.longestSpan() << std::endl;
	} 
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }

	try 
	{
        std::cout << "Errors with the Span bad Shortest: " << bad.shortestSpan() << std::endl;
    } 
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }
    // Test exception when adding more numbers than allowed
    try
	{
        sp.addNumber(12);
    } 
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }

	// Test for HUGE
	Span huge(50000);
	std::srand(std::time(0));
	for (int i = 0; i < 50000; ++i)
	{
        huge.addNumber(std::rand() % 100000); // Random numbers between 0 and 99999
    }

	try 
	{
        std::cout << "Shortest Span: " << huge.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << huge.longestSpan() << std::endl;
		std::cout << "Errors for adding more from range: " << std::endl;
		std::vector<int> additionalNumbers(10, 42); // Ten numbers with the value 42
        huge.addRangeNum(additionalNumbers.begin(), additionalNumbers.end());
	} 
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

