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

FragTrap::FragTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "<<FragTrap default constructor called>>" << this->getname() << " in service." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "<<FragTrap constructor called>> " << this->getname() << " is ready." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "<<FragTrap copy constructor called>> New trap in town named "<< this->getname() << "." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "<<FragTrap Copy assigment operator called>> " << this->getname() << " re-assignation: success." << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
     std::cout << "<<FragTrap Destructor called>>" << this->getname() << " turned to pieces." << std::endl;
}

void FragTrap::highFiveGuys(void)
{
    std::cout << this->getname() << " request a positive high five!! Don't let it down." << std::endl;
}

