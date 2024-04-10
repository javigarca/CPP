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

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal 
{
    public:
        Animal();
        Animal(const std::string& type);
        Animal(const Animal& other);
        virtual ~Animal();

        Animal& operator=(const Animal& other);

        void setType(const std::string& type);
        const std::string getType(void) const;

        virtual void makeSound(void) const;

    protected:
        std::string _type;
};

#endif
