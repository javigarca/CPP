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

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "<<Default constructor called>> "<< this->getname() << " is created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    if (name.empty())
        this->setname("Empty");
    std::cout << "<<Parametric constructor called>> " << this->getname() << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    this->setname(other.getname());
    this->sethitp(other.gethitp());
    this->setenergyp(other.getenergyp());
    this->setattack(other.getattack());
    std::cout << "<<Copy constructor called>> A brand new " << this->getname() << " is created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "<<Destructor called>>" << this->getname() << " to the garbage bin." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->setname(other.getname());
        this->sethitp(other.gethitp());
        this->setenergyp(other.getenergyp());
        this->setattack(other.getattack());
    }
    std::cout << "<<Copy assigment operator called>> Another instance gets " << this->getname() << " re-assignated." << std::endl;
    return *this;
}

const std::string ClapTrap::getname(void) const
{
    return this->_name;
}

int ClapTrap::getenergyp(void) const
{
    return this->_energy_points;
}

int ClapTrap::gethitp(void) const
{
    return this->_hit_points;
}

int ClapTrap::getattack(void) const
{
    return this->_attack_damage;
}

void ClapTrap::setname(const std::string name)
{
    this->_name = name;
}

void ClapTrap::sethitp(const int hit)
{
    this->_hit_points = hit;
}

void ClapTrap::setenergyp(const int energy)
{
    this->_energy_points = energy;
}

void ClapTrap::setattack(const int attack)
{
    this->_attack_damage = attack;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->getenergyp() <= 0 || this->gethitp() <= 0)
    {
        if (this->gethitp() <= 0)
            std::cout << this->getname() << " is dead, mate, no attack. Rest In Peace" << std::endl;
        else
            std::cout << this->getname() << " is exhausted. No energy to perform attack." << std::endl;
        return;
    }
    this->setenergyp(this->getenergyp() - 1);
    if (target.empty())
        std::cout << this->getname() << " attacks no one, causing zero damage to no one" << std::endl;
    else
        std::cout << this->getname() << " attacks " << target << " causing " << this->getattack() << " points of damage." << std::endl;   
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->gethitp() <= 0)
    {    std::cout << this->getname() << " is already dead, mate. Leave it alone" << std::endl;
         return;
    }
    this->sethitp(this->gethitp() - amount);
    std::cout << this->getname() << " receives a vicious attack, causing him to lose " << amount << " points of damage." << std::endl;   
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getenergyp() <= 0 || this->gethitp() <= 0)
    {
        if (this->gethitp() <= 0)
            std::cout << this->getname() << " is dead beyond repair. Rest In Peace" << std::endl;
        else
            std::cout << this->getname() << " is exhausted. No energy to perform repairs." << std::endl;
        return;
    }
    this->setenergyp(this->getenergyp() - 1);
    this->sethitp(this->gethitp() + amount);
    std::cout << this->getname() << " repairs itself, getting " << amount << " hit points back." << std::endl;
}
