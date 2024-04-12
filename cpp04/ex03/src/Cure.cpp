/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:39:19 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 11:39:22 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    this->type = "cure";
    std::cout << "[Cure] << Def Constructor >>" << std::endl;
}

Cure::Cure(const std::string& type) : AMateria(type)
{
    std::cout << "[Cure] << Parametric Constructor >>" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout << "[Cure] << Copy Constructor >>" << std::endl;
}

Cure::~Cure()
{
    std::cout << "[Cure] << Destructor >>" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        this->type = other.type;
     std::cout << "[Cure] << Copy Assignment operator >>" << std::endl;
     return *this;
}

AMateria* Cure::clone() const
{
    AMateria* clone =new Cure(*this);
    return clone;
}

void Cure::use(ICharacter& target)
{
     std::cout << "* heals " << target.getName() <<"’s wounds *" << std::endl;
}
