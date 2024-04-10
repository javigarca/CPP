/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:58:23 by javi              #+#    #+#             */
/*   Updated: 2024/04/10 10:58:27 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "<<FragTrap constructor called>> "<< this->getname() << " is created." << std::endl;
}

FragTrap::~FragTrap()
{
     std::cout << "<<FragTrap Destructor called>>" << this->getname() << " eliminated." << std::endl;
}

