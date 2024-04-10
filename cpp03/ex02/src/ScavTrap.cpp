/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:07:34 by javi              #+#    #+#             */
/*   Updated: 2024/04/09 19:07:38 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "<<ScavTrap Default constructor called>> Welcome "<< this->getname() << "." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout << "<<ScavTrap constructor called>> "<< this->getname() << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "<<ScavTrap copy constructor called>> Say Hello to "<< this->getname() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "<<ScavTrap Copy assigment operator called>> " << this->getname() << " re-assignated succesfully." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "<<ScavTrap Destructor called>>" << this->getname() << " dismantled." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getenergyp() <= 0 || this->gethitp() <= 0)
    {
        if (this->gethitp() <= 0)
            std::cout << this->getname() << " can't attack while dead, sorry." << std::endl;
        else
            std::cout << this->getname() << " is in low battery mode...." << std::endl;
        return;
    }
    this->setenergyp(this->getenergyp() - 1);
    if (target.empty())
        std::cout << this->getname() << " fills the air with beep beep sounds, but nothing to attack" << std::endl;
    else
        std::cout << this->getname() << " brutally attacks " << target << " inflicting " << this->getattack() << " damage points." << std::endl;   
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap serial number " << this->getname() << ". GATE KEEPER MODE ON." << std::endl;
}
