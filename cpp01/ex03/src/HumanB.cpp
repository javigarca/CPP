/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:07:48 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 12:07:50 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
 {}

HumanB::~HumanB()
{}

void HumanB::setWeapon(Weapon& newweapon)
{
    this->_weapon = &newweapon;
}

void HumanB::attack()
{
    if (_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " attacks barehanded" << std::endl;
}
