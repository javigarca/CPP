/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:08:01 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 12:08:04 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(std::string type) : _type(type)
{}

Weapon::~Weapon()
{}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

const std::string& Weapon::getType() const
{
    return _type;
}
