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

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }


    PmergeMe object;
    if (object.parseInput(argc, argv))
    {
        object.display();
        object.display("Before");
        object.sortVector();
        object.sortDeque();
        object.display("After");
    }
    else
        std::cout << "Error" << std::endl;

    return 0;
}
