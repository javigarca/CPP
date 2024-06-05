/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:05:57 by javi              #+#    #+#             */
/*   Updated: 2024/04/11 17:05:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] << Default Constructor >>" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    std::cout << "[Brain] << Copy Constructor >>" << std::endl;
}

Brain::~Brain()
{
    std::cout << "[Brain] << Destructor >>" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    return *this;
     std::cout << "[Brain] << Copy assigment operator >>" << std::endl;
}
