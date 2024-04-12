/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:49:25 by javi              #+#    #+#             */
/*   Updated: 2024/04/10 16:49:27 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        ~WrongCat();

        WrongCat& operator=(const WrongCat& other);

        void makeSound(void) const;
};

#endif
