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

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal 
{
    public:
        AAnimal();
        AAnimal(const std::string& type);
        AAnimal(const AAnimal& other);
        virtual ~AAnimal();

        virtual AAnimal& operator=(const AAnimal& other);

        void setType(const std::string& type);
        const std::string getType(void) const;

        virtual void makeSound(void) const = 0;

    protected:
        std::string _type;
};

#endif
