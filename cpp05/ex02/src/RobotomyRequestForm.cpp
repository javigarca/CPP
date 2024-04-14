/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:43:16 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 22:43:19 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TO_SG 72
#define TO_XE 45

#include "RobotomyRequestForm.hpp"

bool fiftyPerCent() {
    // Inicializa el generador de números aleatorios una vez
    static bool initialized = false;
    if (!initialized) {
        srand(time(NULL));  // Usa la hora actual como semilla
        initialized = true;
    }

    return (rand() % 2);
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", TO_SG, TO_XE), _target("default")
{
    std::cout << "[Robotomy Request Form]>> Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", TO_SG, TO_XE), _target(target)
{
    std::cout << "[Robotomy Request Form]>> Parametric Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
    std::cout << "[Robotomy Request Form]>> Copy Constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[Robotomy Request Form]>> Destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        AForm::operator=(other);    
    return *this;
    std::cout << "[Robotomy Request Form]>> Copy Assignment Operator" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}
        
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    if (fiftyPerCent())
        std::cout << "Luckly for " << this->getTarget() << ", Robotomization has been a success!" << std::endl;
    else
        std::cout << "Bad luck, " << this->getTarget() << " has not been robotomized. Try again?" << std::endl;
}

