/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:13:42 by javi              #+#    #+#             */
/*   Updated: 2024/04/14 17:13:45 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "[Intern]>> Default Constructor" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "[Intern]>> Copy Constructor" << std::endl;
    *this = other;
    return;
}

Intern::~Intern()
{
    std::cout << "[Intern]>> Destructor" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "[Intern]>> Copy Assignmetn operator" << std::endl;
    if (this != &other)
        *this = other;
    return *this;
}

AForm* Intern::createPardon(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::createTree(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobot(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(const std::string& formname, const std::string& formtarget)
{
    AForm* created_form = NULL;

    typedef AForm* (Intern::*Fptr)(const std::string&);

    Fptr forms[3]={&Intern::createPardon, &Intern::createTree, &Intern::createRobot};
    std::string names[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};

    for (int i = 0; i < 3; i++)
    {
        if (formname == names[i])
        {
            created_form = (this->*forms[i])(formtarget);
            break;
        }
    }
    if (created_form)
        std::cout << "Intern creates " << created_form->getName() << "." << std::endl;
    else
        throw FormNotAvailableException();
    return created_form;
}
