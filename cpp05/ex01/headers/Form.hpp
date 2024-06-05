/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:51:19 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 11:51:21 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define MAX_GRADE 1
# define MIN_GRADE 150

# include <exception>
# include <iostream>
# include <string>
# include "Exceptions.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string& name, const unsigned int gradetosign, const unsigned int gradetoexec);
        Form(const Form& other);
        ~Form();

        Form& operator=(const Form& other);

        const std::string getName() const;
        unsigned int getGradeSign() const;
        unsigned int getGradeExec() const;
        bool getIsSigned() const;

        void beSigned(const Bureaucrat& user);
        
    private:
        const std::string   _name;
        bool                _signed;
        const unsigned int  _grade_sign;
        const unsigned int  _grade_exec;               
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
