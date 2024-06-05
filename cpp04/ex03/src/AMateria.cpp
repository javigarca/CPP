/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:04:43 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 11:04:44 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "[AMateria] << Def Constructor >>" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
     std::cout << "[AMateria] << Parametric Constructor >>" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    this->type = other.type;
    std::cout << "[AMateria] << Copy Constructor >>" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "[AMateria] << Copy Assignment Operator >>" << std::endl;
    return *this;
}

AMateria::~AMateria()
{
         std::cout << "[AMateria] << Destructor >>" << std::endl;
}

std::string const & AMateria::getType() const
{
    return this->type;
}
