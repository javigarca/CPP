/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:34:54 by javi              #+#    #+#             */
/*   Updated: 2024/07/05 17:52:19 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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

        bool validateExpresion(const std::string &input) const;
        void showOutput(const std::string &input);

    private:
        std::stack<int> _stack;
};

#endif
