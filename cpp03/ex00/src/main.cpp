/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:43:39 by javi              #+#    #+#             */
/*   Updated: 2024/04/09 20:43:42 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Clappy("Clappy");
    ClapTrap Clappycpy(Clappy);
    ClapTrap Empty("");
    ClapTrap Default;
    ClapTrap Copycat;
    Copycat = Clappy;   
    std::cout << "**** Enought ClapTraps *****" << std::endl;
    Clappy.setattack(2);
    Clappy.attack("Empty");
    Empty.takeDamage(Clappy.getattack());
    Empty.beRepaired(Clappy.getattack());
    Clappy.setattack(20);
    Default.setenergyp(1);
    Default.sethitp(21);
    Empty.setattack(21);
    Empty.attack("Default");
    Default.takeDamage(Empty.getattack());
    Default.beRepaired(1);
    Clappy.attack(Default.getname());
    Default.takeDamage(Clappy.getattack());
    Default.beRepaired(4);
    Default.attack("");
    Empty.attack("");
    Empty.setenergyp(0);
    Empty.beRepaired(2);

    return 0;
}
