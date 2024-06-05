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

# include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "[Dog] << Default Constructor >>" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "[Dog] << Copy Constructor >>" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[Dog] << Destructor >>" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "[Dog] << Copy assignment operator >>" << std::endl;
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "The dog barks to reclaim your attention" << std::endl;
}
