/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:55:29 by javi              #+#    #+#             */
/*   Updated: 2024/04/01 16:11:13 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resources.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

void menu(void)
{
    std::cout << " †††††††††††††††††††††††††††††††" << std::endl;
    std::cout << " [*]-[*] " << "\033[33mPhoneBook v.1.0 \033[0m[*]-[*]" << std::endl;
    std::cout << " †††††††††††††††††††††††††††††††" << std::endl;
    std::cout << std::endl << " Menu options: " << std::endl;
    std::cout << " *************" << std::endl;
    std::cout << " <ADD> : Add a new contact. (limited to " << MAX_CONTACTS << ")" << std::endl;
    std::cout << " <SEARCH> : Search for and print a contact info." << std::endl;
    std::cout << " <EXIT> : Terminate this program." << std::endl;
    std::cout << " Enter option >>> ";
}

int main()
{
    PhoneBook   pb;
    std::string input;

    system("clear");
    while (1)
    {
        menu();
        std::cin >> input;
        if (!input.compare("EXIT"))
        {
            system("clear");
            std::cout << std::endl << "\033[33mThank you for using PhoneBook! See you soon.";
            return(0);
        }
        else if (!input.compare("SEARCH"))
            {
                system("clear");
                pb.print_contacts();
            }
        else if (!input.compare("ADD"))
            {
                system("clear");
                std::cout << pb.add_contacts();
            }
            std::cout << std::endl;        
    }
    return(0);
}
