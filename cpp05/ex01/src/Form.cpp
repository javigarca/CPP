/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:51:19 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 21:52:54 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _signed(false), _grade_sign(MIN_GRADE), _grade_exec(MIN_GRADE)
{
    std::cout << "[Form]>> Default Constructor" << std::endl;
}

Form::Form(const std::string& name, const unsigned int gradetosign, const unsigned int gradetoexec) : _name(name), _signed(false), _grade_sign(gradetosign), _grade_exec(gradetoexec)
{
    std::cout << "[Form]>> Parametric Constructor" << std::endl;
     if ((gradetosign < MAX_GRADE) || (gradetoexec < MAX_GRADE))
        throw GradeTooHighException();
    else if ((gradetosign > MIN_GRADE) || (gradetoexec > MIN_GRADE))
        throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec)
{
    std::cout << "[Form]>> Copy Constructor" << std::endl;
}

Form::~Form()
{
    std::cout << "[Form]>> Destructor" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "[Form]>> Copy Assignment Operator" << std::endl;
    if (this != &other)
        this->_signed = other._signed;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form: " << obj.getName() << std::endl;
    os << "Level Ex: " << obj.getGradeExec() << std::endl;
    os << "Level Si: " << obj.getGradeSign() << std::endl;
    if (obj.getIsSigned())
        os << "Status: Signed" << std::endl;
    else
        os << "Status: NOT Signed" << std::endl;
    return os;
}

const std::string Form::getName() const
{
    return this->_name;
}

unsigned int Form::getGradeSign() const
{
    return this->_grade_sign;
}

unsigned int Form::getGradeExec() const
{
    return this->_grade_exec;
}

bool Form::getIsSigned() const
{
    return this->_signed;
}

void Form::beSigned(const Bureaucrat& user)
{
    if (this->getIsSigned())
        throw SignedFormException();
    if (user.getGrade() > this->getGradeSign())
        throw GradeTooLowException();
    this->_signed = true;
    std::cout << "Signature complete." << std::endl;
}

