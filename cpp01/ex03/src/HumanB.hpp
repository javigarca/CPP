/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:07:56 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 12:07:59 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon* _weapon; // as a pointer, as it can be no weapon, or null

    public:
        HumanB(std::string name);
        ~HumanB();

        void attack();
        void setWeapon(Weapon& newweapon);
};

#endif
