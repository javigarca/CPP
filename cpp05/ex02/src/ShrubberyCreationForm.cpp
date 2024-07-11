/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:43:02 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 22:43:07 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TO_SG 145
#define TO_XE 137

#include "ShrubberyCreationForm.hpp"
#include <fstream>

void shrubberyTree(const std::string& target)
{
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Failed to open the file: " << filename << std::endl;
        return;
    }
    file    << "               * *    " << std::endl;
    file    << "            *    *  *" << std::endl;
    file    << "       *  *    *     *  *" << std::endl;
    file    << "      *     *    *  *    *" << std::endl;
    file    << "  * *   *    *    *    *   *" << std::endl;
    file    << "  *     *  *    * * .#  *   *" << std::endl;
    file    << "  *   *     * #.  .# *   *" << std::endl;
    file    << "   *      #.  #: #  * *    *" << std::endl;
    file    << "  *   * *  #. ##        *" << std::endl;
    file    << "    *        ###" << std::endl;
    file    << "              ##" << std::endl;
    file    << "               ##." << std::endl;
    file    << "               .##:" << std::endl;
    file    << "               :###" << std::endl;
    file    << "              ;###" << std::endl;
    file    << "             ,####."  << std::endl;
    file    << "^__________.######.___________^"  << std::endl;
    file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", TO_SG, TO_XE), _target("default")
{
    std::cout << "[Shrubbery Creation Form]>> Default Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", TO_SG, TO_XE), _target(target)
{
    std::cout << "[Shrubbery Creation Form]>> Parametric Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
    std::cout << "[Shrubbery Creation Form]>> Copy Constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[Shrubbery Creation Form]>> Destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        AForm::operator=(other);    
    return *this;
    std::cout << "[Shrubbery Creation Form]>> Copy Assignment Operator" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}
        
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
    shrubberyTree(this->getTarget());
}
