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

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default")
{
    std::cout << "[WrongAnimal] << Def Constructor >>" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
    std::cout << "[WrongAnimal] << Parametric Constructor >>" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    this->_type = other._type;
    std::cout << "[WrongAnimal] << Copy Constructor >>" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] << Destructor >>" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "[WrongAnimal] << Copy assigment operator >>" << std::endl;
    return *this;
}

void WrongAnimal::setType(const std::string& type)
{
    this->_type = type;
}

const std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "The WrongAnimal produces a characteristic sound." << std::endl;
}
