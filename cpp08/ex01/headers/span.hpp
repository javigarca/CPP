/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:57:53 by javi              #+#    #+#             */
/*   Updated: 2024/06/29 18:57:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <vector>
#include <stdexcept>

class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();

        Span & operator=(const Span &other);

        void addNumber(int nadd);
        void addRangeNum(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan() const;
        int longestSpan() const;

        class MaxNumberReached : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class MinElements : public std::exception
        {
            public:
                const char* what() const throw();
        };

    private:
        unsigned int        _max_numbers;
        std::vector<int>    _numbers;
};

#endif
