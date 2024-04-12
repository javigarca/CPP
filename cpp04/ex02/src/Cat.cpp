/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:49:25 by javi              #+#    #+#             */
/*   Updated: 2024/04/10 16:49:27 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain())
{
    std::cout << "[Cat] << Default Constructor >>" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain))
{
    std::cout << "[Cat] << Copy Constructor >>" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[Cat] << Destructor >>" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        AAnimal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    std::cout << "[Cat] << Copy assigment operator >>" << std::endl;
    return *this; 
}

void Cat::makeSound(void) const
{
    std::cout << "The cat meows into oblivion." << std::endl;
}
