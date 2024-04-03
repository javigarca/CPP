/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:07:32 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 12:07:34 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

 HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
 {}

 HumanA::~HumanA()
 {}

 void HumanA::attack()
 {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
 }

