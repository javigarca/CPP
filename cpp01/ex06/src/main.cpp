/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:50:54 by javi              #+#    #+#             */
/*   Updated: 2024/04/03 21:50:56 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    Harl harl;
    
    if (argc != 2)
    {
        std::cout << "Incorrect number of parameters." << std::endl;
        std::cout << "Usage: " << argv[0] << " <desired level> OR <anything else>." << std::endl;
        std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
    }
    else
    {
        std::string level = argv[1];
        harl.complain(level);
    }
}
