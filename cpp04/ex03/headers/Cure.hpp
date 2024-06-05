/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:39:09 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 11:39:12 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const std::string& type);
        Cure(const Cure& other);
        ~Cure();

        Cure& operator=(const Cure& other);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);

};

#endif
