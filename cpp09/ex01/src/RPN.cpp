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

#include "../headers/RPN.hpp"

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
        (void)other;
    return *this;
}

bool RPN::validateExpression(const std::string &input) const
{
    if (input.empty())
    {
        std::cout << "Empty expression" << std::endl;
        return false;
    }

    size_t operandCount = 0; // Contador para operandos
    size_t operatorCount = 0; // Contador para operadores

    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        char c = *it;
        if (!std::isdigit(c) && c != '+' && c != '-' && c != '/' && c != '*' && c != ' ' && c != '\t')
        {
            std::cout << "Invalid character in expression." << std::endl;
            return false;
        }
        if (std::isdigit(c))
        {
            // Contar el número de dígitos consecutivos como un solo operando
            while (it != input.end() && std::isdigit(*it))
            {
                ++it;
            }
            --it; // Volver un carácter atrás ya que el bucle interno avanza uno de más al encontrar un operator
            operandCount++;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            operatorCount++;
            if (operatorCount >= operandCount)
            {
                std::cout << "Invalid expression: too many operators." << std::endl;
                return false;
            }
        }
    }

    // Al final, debe haber exactamente un operando más que operadores
    if (operandCount != operatorCount + 1)
    {
        std::cout << "Invalid expression: mismatch between operators and operands." << std::endl;
        return false;
    }

    return true;
}


void RPN::resolve(const std::string &input) const
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
