/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:26:43 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 11:26:49 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << std::endl;
    std::cout << ">>>>>>>>>>----ADDRESSES----<<<<<<<<<<" << std::endl;
    std::cout << "This is the memory address of the string str: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << ">>>>>>>>>>----VALUES----<<<<<<<<<<" << std::endl;
    std::cout << "This is the value of the string str: " << str << std::endl;
    std::cout << "The value held by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value held by stringREF: " << stringREF << std::endl;
}
