/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:55:58 by javi              #+#    #+#             */
/*   Updated: 2024/07/03 14:56:01 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &other) : std::stack<T>(&other) {}
        ~MutantStack() {}

        MutantStack& operator=(const MutantStack &other)
        {
            if (this != &other)
                std::stack<T>::operator=(&other);
            return *this;
        }
        
        typedef typename std::stack<T>::container_type container_type;
        typedef typename container_type::iterator iterator;
        typedef typename container_type::reverse_iterator reverse_iterator;
        typedef typename container_type::const_iterator const_iterator;
        typedef typename container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
