/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:58:35 by javi              #+#    #+#             */
/*   Updated: 2024/04/15 11:58:37 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}


static bool pseudoliteral(const std::string& literal)
{
    std::string pseudos[8] = {"inf", "-inf", "inff", "-inff", "nan", "nanf", "+inf", "+inff"};

    int res = -1;
    std::string d, f;
    for (int i = 0; i < 8; ++i)
    {
        if (literal.compare(pseudos[i]) == 0)
        {
            res = i;
            break;
        }
    }
    switch (res)
    {
        case -1:
            return false;
        case 0:
        case 2:
            d = pseudos[0];
            f = pseudos[2];
            break;
        case 1:
        case 3:
            d = pseudos[1];
            f = pseudos[3];
            break;
        case 4:
        case 5:
            d = pseudos[4];
            f = pseudos[5];
            break;
        case 6:
        case 7:
            d = pseudos[6];
            f = pseudos[7];
            break;
        default:
            break;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
    return true;
}

// Función de conversión principal
void ScalarConverter::convert(const std::string& literal)
{
    if (pseudoliteral(literal))
        return;

    if (isChar(literal))
    {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
    else if (isInt(literal))
    {
        long l = std::strtol(literal.c_str(), NULL, 10);
        if (errno != ERANGE && l <= std::numeric_limits<int>::max() && l >= std::numeric_limits<int>::min())
        {
            int i = static_cast<int>(l);
            printChar(static_cast<char>(i));
            printInt(i);
            printFloat(static_cast<float>(i));
            printDouble(static_cast<double>(i));
        }
        else
        {
            std::cout << "Conversion out of range for int" << std::endl;
        }
    }
    else if (isFloat(literal))
    {
        float f = std::strtof(literal.c_str(), NULL);
        if (errno != ERANGE)
        {
            printChar(static_cast<char>(f));
            if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max()) 
                std::cout << "int: impossible" << std::endl;
            else
                printInt(static_cast<int>(f));
            printFloat(f);
            printDouble(static_cast<double>(f));
        }
        else
        {
            std::cout << "Conversion out of range for float" << std::endl;
        }
    }
    else if (isDouble(literal))
    {
        double d = std::strtod(literal.c_str(), NULL);
        if (errno != ERANGE)
        {
            printChar(static_cast<char>(d));
            if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) 
                std::cout << "int: impossible" << std::endl;
            else
                printInt(static_cast<int>(d));
            printFloat(static_cast<float>(d));
            printDouble(d);
        }
        else
        {
            std::cout << "Conversion out of range for double" << std::endl;
        }
    }
    else
    {
        std::cout << "Conversion is impossible" << std::endl;
    }
}

// Funciones auxiliares para verificar tipos
bool ScalarConverter::isChar(const std::string& literal)
{
    return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty()) return false;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.size(); ++i) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.empty() || literal == "." || literal == "-." || literal == "+.") return false;
    bool dotFound = false;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.size() - 1; ++i) {
        if (literal[i] == '.') {
            if (dotFound) return false; // Second dot found
            dotFound = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    // Last character must be 'f'
    return literal[literal.length() - 1] == 'f';
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    if (literal.empty() || literal == "." || literal == "-." || literal == "+.") return false;
    bool dotFound = false;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.size(); ++i) {
        if (literal[i] == '.') {
            if (dotFound) return false; // Second dot found
            dotFound = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

// Funciones de impresión
void ScalarConverter::printChar(char c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: " << d << std::endl;
}


