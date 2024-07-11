/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Internn.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:13:46 by javi              #+#    #+#             */
/*   Updated: 2024/04/14 17:13:47 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef InternN_HPP
# define InternN_HPP

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Exceptions.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();

        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string& formname, const std::string& formtarget);

        AForm* createPardon(const std::string& target);
        AForm* createTree(const std::string& target);
        AForm* createRobot(const std::string& target);
        //typedef void (Intern::*FuncPtr)();

    //private:
      //  FuncPtr _form_type[3];
};

#endif
