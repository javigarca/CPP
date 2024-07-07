/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:35:04 by javi              #+#    #+#             */
/*   Updated: 2024/07/07 16:55:35 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe::~PmergeMe()
{}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
        this->_deque = other._deque;
        this->_vector = other._vector;
    return *this;
}

bool PmergeMe::isValidNumber(const std::string& str, int& number)
{
    std::stringstream ss(str);
    ss >> number;
    // Verificar si la conversión falló o si hay caracteres adicionales en la cadena
    if (ss.fail() || !ss.eof() || number < 0)
        return false;
    return true;
}

bool PmergeMe::extractValidNumbers(const std::string& str, std::vector<int>& validNumbers)
{
    std::stringstream ss(str);
    std::string token;
    while (ss >> token)
    {
        int number;
        if (isValidNumber(token, number))
            validNumbers.push_back(number);
        else
            return true;
    }
    return false;
}

bool PmergeMe::parseInput(int argc, char *argv[])
{
    std::vector<int> validNumbers;
    for (int i = 0; i < argc; ++i)
    {
        if (extractValidNumbers(argv[i], validNumbers))
        return false;
    }
        
    if (validNumbers.size() < 2)
    {
        std::cout << "Error" << std::endl;
        return false;
    }
    
    std::cout << "GOOD" << std::endl;
    return true;
}

void PmergeMe::display(const std::string &title)
{
    std::cout << title << ": ";

    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it)
        std::cout <<  *it << " ";
    std::cout << std::endl;
}

void PmergeMe::sortVector()
{
    std::cout << "VECTOR SORT." << std::endl;
    return;
}

void PmergeMe::sortDeque()
{
    std::cout << "DEQEUE SORT." << std::endl;
    return;
}
