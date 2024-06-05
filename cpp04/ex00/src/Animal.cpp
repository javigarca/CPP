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

#include "Animal.hpp"

Animal::Animal() : _type("default")
{
    std::cout << "[Animal] << Def Constructor >>" << std::endl;
}

Animal::Animal(const std::string& type) : _type(type)
{
    std::cout << "[Animal] << Parametric Constructor >>" << std::endl;
}

Animal::Animal(const Animal& other)
{
    this->_type = other._type;
    std::cout << "[Animal] << Copy Constructor >>" << std::endl;
}

Animal::~Animal()
{
    std::cout << "[Animal] << Destructor >>" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "[Animal] << Copy assigment operator >>" << std::endl;
    return *this;
}

void Animal::setType(const std::string& type)
{
    this->_type = type;
}

const std::string Animal::getType(void) const
{
    return this->_type;
}

void Animal::makeSound(void) const
{
    std::cout << "The animal produces a characteristic sound." << std::endl;
}
