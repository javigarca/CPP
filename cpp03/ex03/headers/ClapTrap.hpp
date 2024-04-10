/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:07:41 by javi              #+#    #+#             */
/*   Updated: 2024/04/09 19:07:43 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        virtual ~ClapTrap();

        ClapTrap& operator=(const ClapTrap& other);

        const std::string getname(void) const;
        int getenergyp(void) const;
        int gethitp(void) const;
        int getattack(void) const;
        void setname(const std::string name);
        void sethitp(const int hit);
        void setenergyp(const int energy);
        void setattack(const int attack);

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
    protected:
        std::string _name;
        int         _hit_points;
        int         _energy_points;
        int         _attack_damage;
};

#endif
