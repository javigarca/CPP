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
#include <stack>
#include <iostream>
#include <cctype>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        ~RPN();

        RPN & operator=(const RPN &other);

        bool validateExpression(const std::string &input) const;
        void resolve(const std::string &input);
        
    private:
        std::stack<double> _stack;
        int             _result;
};

#endif
