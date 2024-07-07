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
        *this = other;
    return *this;
}

bool RPN::validateExpression(const std::string &input) const
{
    if (input.empty())
    {
        std::cout << "Empty expression" << std::endl;
        return false;
    }

    size_t i = 0;
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        char c = *it; 
        if (!std::isdigit(c) && c != '+' && c != '-' && c != '/' && c != '*' && c !=' ')
        {
            std::cout << "Invalid character in expression." << std::endl;
            return false;
        }
        if (std::isdigit(c))
            i++;
    }
    
    if (i > 9)
    {
        std::cout << "Too many numbers." << std::endl;
        return false;
    }
    return true;
}

void RPN::resolve(const std::string &input)
{
    std::stack<double> stack;
    
    for (size_t i = 0; i < input.size(); ++i)
    {
        char c = input[i];
        
        if (std::isdigit(c))
            stack.push(c - '0');
        else if (c == ' ')
            continue;
        else
        {
            if (stack.size() < 2)
            {
                std::cout << "Error: incorrect expression." << std::endl;
                return;
            }

            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            switch (c)
            {
                case '+': 
                    stack.push(a + b); 
                    break;
                case '-': 
                    stack.push(a - b);
                    break;
                case '*': 
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0)
                    {
                        std::cout << "Error: division by zero." << std::endl;
                        return;
                    }
                    stack.push(a / b);
                    break;
                default:
                    std::cout << "Error:" << c << std::endl;
                    return;
            }
        }
    }

    if (stack.size() != 1)
    {
        std::cout << "Error: invalid expression." << std::endl;
        return;
    }
    std::cout << "Result: " << stack.top() << std::endl;
}
