/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:09:06 by javi              #+#    #+#             */
/*   Updated: 2024/04/02 00:09:11 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
    public:
            Zombie();
            Zombie(std::string name);
            ~Zombie();

            void anounce(void) const;
            void setName(std::string name);
    private:
            std::string _name;
};

#endif
