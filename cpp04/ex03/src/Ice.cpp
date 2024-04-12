/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:39:23 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 11:39:25 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    this->type = "ice";
    std::cout << "[Ice] << Def Constructor >>" << std::endl;
}

Ice::Ice(const std::string& type) : AMateria(type)
{
    std::cout << "[Ice] << Parametric Constructor >>" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout << "[Ice] << Copy Constructor >>" << std::endl;
}

Ice::~Ice()
{
    std::cout << "[Ice] << Destructor >>" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        this->type = other.type;
     std::cout << "[Ice] << Copy Assignment operator >>" << std::endl;
     return *this;
}

AMateria* Ice::clone() const
{
    AMateria* clone =new Ice(*this);
    return clone;
}

void Ice::use(ICharacter& target)
{
     std::cout << "* shots an ice bolt at " << target.getName() << std::endl;
}

