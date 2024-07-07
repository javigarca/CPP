/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:51:41 by javi              #+#    #+#             */
/*   Updated: 2024/07/05 17:51:44 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <inverted Polish mathematical expression>" << std::endl;
        return 1;
    }

    RPN rpn;
    std::string exprs = std::string(argv[1]);
    if (rpn.validateExpression(exprs))
        rpn.resolve(exprs);
    else
        std::cout << "Error." << std::endl;
    return 0;
}
