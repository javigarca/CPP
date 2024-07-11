/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:56:21 by javi              #+#    #+#             */
/*   Updated: 2024/07/03 14:56:24 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // Iterate using the standard iterator
    std::cout << "Iterating from begin to end:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Iterate using the reverse iterator
    std::cout << "Iterating from rbegin to rend:" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Iterate using the constant iterator
    std::cout << "Iterating from begin to end with const_iterator:" << std::endl;
    for (MutantStack<int>::const_iterator cit = mstack.begin(); cit != mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Iterate using the constant reverse iterator
    std::cout << "Iterating from rbegin to rend with const_reverse_iterator:" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = mstack.rbegin(); crit != mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
   std::cout << std::endl;
   std::cout << "+++++++++++++++++++++++LIST+++++++++++++++" << std::endl;

   std::list<int> lmstack;
    lmstack.push_back(5);
    lmstack.push_back(17);
    std::cout << lmstack.back() << std::endl;
    lmstack.pop_back();
    std::cout << lmstack.size() << std::endl;
    lmstack.push_back(3);
    lmstack.push_back(5);
    lmstack.push_back(737);
    lmstack.push_back(0);
    std::list<int>::iterator lit = lmstack.begin();
    std::list<int>::iterator lite = lmstack.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    // Iterate using the standard iterator
    std::cout << "Iterating from begin to end:" << std::endl;
    for (std::list<int>::iterator lit = lmstack.begin(); lit != lmstack.end(); ++lit) {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;

    // Iterate using the reverse iterator
    std::cout << "Iterating from rbegin to rend:" << std::endl;
    for (std::list<int>::reverse_iterator lrit = lmstack.rbegin(); lrit != lmstack.rend(); ++lrit) {
        std::cout << *lrit << " ";
    }
    std::cout << std::endl;

    // Iterate using the constant iterator
    std::cout << "Iterating from begin to end with const_iterator:" << std::endl;
    for (std::list<int>::iterator lcit = lmstack.begin(); lcit != lmstack.end(); ++lcit) {
        std::cout << *lcit << " ";
    }
    std::cout << std::endl;

    // Iterate using the constant reverse iterator
    std::cout << "Iterating from rbegin to rend with const_reverse_iterator:" << std::endl;
    for (std::list<int>::reverse_iterator lcrit = lmstack.rbegin(); lcrit != lmstack.rend(); ++lcrit) {
        std::cout << *lcrit << " ";
    }
   std::cout << std::endl;

    return (0);
}
