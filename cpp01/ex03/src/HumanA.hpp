/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:07:40 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 12:07:44 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon; 

    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();

        void attack();
};

#endif
