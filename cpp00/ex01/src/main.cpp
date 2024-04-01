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
    std::cout << "\033[35m    <ADD> : " << "\033[0mAdd a new contact. (limited to " << MAX_CONTACTS << ")" << std::endl;
    std::cout << "\033[35m <SEARCH> : " << "\033[0mSearch for and print a contact info." << std::endl;
    std::cout << "\033[35m   <EXIT> : " << "\033[0mTerminate this program." << std::endl;
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
        else
            {
                system("clear");
                std::cout << "\033[31mPlease, select ADD, SEARCH or EXIT. Capital letters only. Try again.\033[0m";
            } 
            std::cout << std::endl;        
    }
    return(0);
}
