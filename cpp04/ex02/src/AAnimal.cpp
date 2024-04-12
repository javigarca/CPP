/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:49:25 by javi              #+#    #+#             */
/*   Updated: 2024/04/10 16:49:27 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default")
{
    std::cout << "[AAnimal] << Def Constructor >>" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : _type(type)
{
    std::cout << "[AAnimal] << Parametric Constructor >>" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    this->_type = other._type;
    std::cout << "[AAnimal] << Copy Constructor >>" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal] << Destructor >>" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "[AAnimal] << Copy assigment operator >>" << std::endl;
    return *this;
}

void AAnimal::setType(const std::string& type)
{
    this->_type = type;
}

const std::string AAnimal::getType(void) const
{
    return this->_type;
}
