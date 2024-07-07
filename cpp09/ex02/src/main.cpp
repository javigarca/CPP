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
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <positive integer sequence, each integer an argument>" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe object;
        std::string exprs = std::string(argv[1]);
        if (object.parseInput(argc, argv))
        {
            object.display("Before");
            object.sortVector();
            object.sortDeque();
            object.display("After");
        }
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
    
    return 0;
}
