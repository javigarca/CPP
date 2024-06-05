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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamonTrap.hpp"

int main(void)
{
    /*
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "**** ClapTraps *****" << std::endl;
    std::cout << "********************" << std::endl;
    ClapTrap Clappy("Clappy");
    ClapTrap Clappycpy(Clappy);
    ClapTrap Empty("");
    ClapTrap Default;
    ClapTrap Copycat;
    Copycat = Clappy;   
    std::cout << "**** Enough ClapTraps *****" << std::endl;
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
    
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "**** ScavTraps *****" << std::endl;
    std::cout << "********************" << std::endl;
    ScavTrap Clappy("Clappy");
    ScavTrap Clappycpy(Clappy);
    ScavTrap Empty("");
    ScavTrap Default;
    ScavTrap Copycat;
    Copycat = Clappy;
    ScavTrap st("ST-1");
    st.attack("an enemy");
    st.attack("");
    st.setenergyp(0);
    st.attack("another enemy");
    st.setenergyp(2);
    st.sethitp(0);
    st.attack("another enemy");
    st.takeDamage(4);
    st.beRepaired(3);
    st.sethitp(10);
    st.setenergyp(4);
    st.takeDamage(4);
    st.beRepaired(3);
    st.guardGate();

    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "**** FragTraps *****" << std::endl;
    std::cout << "********************" << std::endl;
    FragTrap Clappy("Clappy");
    FragTrap Clappycpy(Clappy);
    FragTrap Empty("");
    FragTrap Default;
    FragTrap Copycat;
    Copycat = Clappy;
    FragTrap ft("FT-2");
    ft.attack("an enemy");
    ft.attack("");
    ft.setenergyp(0);
    ft.attack("another enemy");
    ft.setenergyp(2);
    ft.sethitp(0);
    ft.attack("another enemy");
    ft.takeDamage(4);
    ft.beRepaired(3);
    ft.sethitp(10);
    ft.setenergyp(4);
    ft.takeDamage(4);
    ft.beRepaired(3);
    ft.highFiveGuys();
*/
    std::cout << std::endl;
    std::cout << "********************" << std::endl;
    std::cout << "*** DiamondTraps ***" << std::endl;
    std::cout << "********************" << std::endl;
    // Crear una instancia de DiamondTrap
    DiamondTrap dt("DiamondHero");
    // Probar la funcionalidad de ataque de ScavTrap
    dt.attack("an enemy");
    // Probar la capacidad especial de FragTrap
    dt.highFiveGuys();
    // Probar la capacidad especial de ScavTrap
    dt.guardGate();
    // Probar la capacidad única de DiamondTrap
    dt.whoAmI();
    // Crear una copia de DiamondTrap usando el constructor de copia
    DiamondTrap dtCopy = dt;
    // Mostrar el estado de la copia para verificar que se copió correctamente
    std::cout << "Copy created" << std::endl;
    dtCopy.whoAmI();
    // Asignar un DiamondTrap a otro usando el operador de asignación
    DiamondTrap dtAssigned("AssignedHero");
    dtAssigned = dt;
    // Mostrar el estado después de la asignación
    std::cout << "After assignment" << std::endl;
    dtAssigned.whoAmI();
    return 0;
}
