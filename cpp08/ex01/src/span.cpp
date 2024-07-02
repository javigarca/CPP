/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:57:53 by javi              #+#    #+#             */
/*   Updated: 2024/06/29 18:57:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : _max_numbers(0) 
{}

Span::Span(unsigned int n) : _max_numbers(n) 
{}

Span::Span(const Span &other)
{
    this->_max_numbers = other._max_numbers;
    this->_numbers = other._numbers;
}

Span::~Span()
{}

Span & Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->_max_numbers = other._max_numbers;
        this->_numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int nadd)
{
    if (_numbers.size() >= _max_numbers)
        throw MaxNumberReached();
    _numbers.push_back(nadd);
}

void Span::addRangeNum(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _numbers.size() > _max_numbers)
        throw MaxNumberReached();
    _numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw MinElements();
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    unsigned int prevmin = sorted[0] - sorted[1];
    for (size_t i = 2; i < sorted.size(); i++)
    {
        unsigned int newmin = sorted[i] - sorted[i - 1];
        if (newmin < prevmin)
            prevmin = newmin;
    }
    return prevmin;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw MinElements();
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return (max - min);
}

const char* Span::MaxNumberReached::what() const throw()
{
    return ("Maximun size of vector reached");
}

const char* Span::MinElements::what() const throw()
{
    return ("Not enough elements present for this action");
}
