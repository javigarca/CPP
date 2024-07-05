/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:35:04 by javi              #+#    #+#             */
/*   Updated: 2024/07/05 18:32:33 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN::~RPN()
{}

RPN & RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

bool RPN::validateExpresion(const std::string &input) const
{
    size_t i = 0;
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        char c = *it; 
        if (!std::isdigit(c) && c != '+' && c != '-' && c != '/' && c != '*')
        {
            std::cout << "Invalid character in expression." << std::endl;
            return false;
        }
        if (std::isdigit(c))
            i++;
    }
    if (i > 10)
    {
        std::cout << "Too many numbers." << std::endl;
        return false;
    }
    return true;
}

void RPN::showOutput(const std::string &input)
{
    if (!input.empty())
        std::cout << "bien" << std::endl;
    else
        std::cout << "vacio" << std::endl;
}


