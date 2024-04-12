/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:39:13 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 11:39:18 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const std::string& type);
        Ice(const Ice& other);
        ~Ice();

        Ice& operator=(const Ice& other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);

};

#endif
