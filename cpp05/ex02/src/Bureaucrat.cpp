/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:53:57 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 00:54:00 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Newbie"), _grade(150)
{
    std::cout << "[Bureaucrat]>> Default Constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int const grade) : _name(name)
{
    std::cout << "[Bureaucrat]>> Parametric Constructor" << std::endl;
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (grade > MIN_GRADE)
        throw GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "[Bureaucrat]>> Copy Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat]>> Destructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "[Bureaucrat]>> Copy Assignment Operator" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << " * Bureaucrat named: " << obj.getName() << " holding grade: " << obj.getGrade() << " *" << std::endl;
    return os;
}

std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

unsigned int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == MAX_GRADE)
        throw GradeTooHighException();
    this->_grade -= 1; 
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == MIN_GRADE)
        throw GradeTooLowException();
    this->_grade += 1;
}

void Bureaucrat::signForm(AForm& formtosign)
{
    try
    {
        formtosign.beSigned(*this);
        std::cout << this->getName() << " signed " << formtosign.getName() << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << formtosign.getName() << " because " << e.what() << std::endl;
    }
}
