/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:08:08 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 12:08:10 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
    std::string _type;

public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();

    void setType(std::string type);
    const std::string& getType() const;
};

#endif
