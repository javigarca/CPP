/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:43:28 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 22:43:30 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TO_SG 25
#define TO_XE 5

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", TO_SG, TO_XE), _target("default")
{
    std::cout << "[Presidential Pardon Form]>> Default Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", TO_SG, TO_XE), _target(target)
{
    std::cout << "[Presidential Pardon Form]>> Parametric Constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& pardon) : AForm(pardon), _target(pardon._target)
{
    std::cout << "[Presidential Pardon Form]>> Copy Constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[Presidential Pardon Form]>> Destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& pardon)
{
    if (this != &pardon)
        AForm::operator=(pardon);    
    return *this;
    std::cout << "[Presidential Pardon Form]>> Copy Assignment Operator" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}
        
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    std::cout << "Hereby, " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
