/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:49:25 by javi              #+#    #+#             */
/*   Updated: 2024/04/10 16:49:27 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] << Default Constructor >>" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "[Cat] << Copy Constructor >>" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[Cat] << Destructor >>" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "[Cat] << Copy assigment operator >>" << std::endl;
    return *this; 
}

void Cat::makeSound(void) const
{
    std::cout << "The cat meows into oblivion." << std::endl;
}
