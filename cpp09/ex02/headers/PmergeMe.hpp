/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:34:54 by javi              #+#    #+#             */
/*   Updated: 2024/07/07 16:54:52 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();

        PmergeMe & operator=(const PmergeMe &other);

        bool parseInput(int argc, char* argv[]);
        bool extractValidNumbers(const std::string& str, std::vector<int>& validNumbers);
        bool isValidNumber(const std::string& str, int& number);
        void sortVector();
        void sortDeque();
        void display(const std::string &title) const;
        void display() const;
        
    private:
        std::vector<int>    _vector;
        std::deque<int>     _deque;
};

#endif
