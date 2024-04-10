/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:16:02 by javi              #+#    #+#             */
/*   Updated: 2024/04/10 12:16:04 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamonTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_name = "default";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;

    this->ClapTrap::_name = this->_name + "_clap_name";
    std::cout << "<<DiamondTrap Default constructor called>> " << this->_name << " is online." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->ClapTrap::_name = name + "_clap_name";
    this->_name = name;
    this->_hit_points = FragTrap::_hit_points;
    this->_energy_points = ScavTrap::_energy_points;
    this->_attack_damage = FragTrap::_attack_damage;
    std::cout << "<<DiamondTrap constructor called>> " << this->_name << " is online." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    _name = other._name;
    std::cout << "<<DiamondTrap copy constructor called>> New diamond named " << this->_name << "." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "<<DiamondTrap destructor called>> Diamond named " << this->_name << " disassembled." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ScavTrap::operator=(other);  
        FragTrap::operator=(other);  
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "<<DiamondTrap Copy assigment operator called>> " << this->getname() << " recarved successfully." << std::endl;
    return *this;
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
    std::cout << "I'm "<< this->_name << ". Also known as " << ClapTrap::_name << "." << std::endl;
}
