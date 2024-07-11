/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:53:51 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 00:53:55 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat A("James", 1);
    Intern randomIntern;
    AForm* form[4];
    std::cout << "A random Intern is here to produce a form of each type." << std::endl;
    form[0] = randomIntern.makeForm("shrubbery creation", "Home");
    std::cout << *form[0] << std::endl;
    form[1] = randomIntern.makeForm("presidential pardon", "Algubert Zokton");
    std::cout << *form[1] << std::endl;
    form[2] = randomIntern.makeForm("robotomy request", "Bren Zx");
    std::cout << *form[2] << std::endl;
    std::cout << "Now the intern will try to produce a ""Change Boss Request"" that doesn't exist" << std::endl;
    try
    {
    form[3] = randomIntern.makeForm("Change Boss Request", "Please");
    std::cout << *form[3] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        form[3] = NULL;
    }
    std::cout << "**************************************" << std::endl;
    std::cout << "His boos James is here to sign and execute." << std::endl;
    for (int i = 0;i < 3; i++)
    {
        A.signForm(*form[i]);
        A.executeForm(*form[i]);
    }
    std::cout << "**************************************" << std::endl;
    std::cout << "That's all folks!" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (form[i])
            delete form[i];
    }
}
