/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:03:59 by javi              #+#    #+#             */
/*   Updated: 2024/03/28 12:04:01 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _book_size(0), _next_index(0)
{}
PhoneBook::~PhoneBook(void)
{}

std::string format_view_str(std::string str, size_t len)
{
    if ((str.length() > len) && len)
        return (str.substr(0, len - 1) + ".");
    else
        return(str);

}

void pause() {
    std::cout << "\033[5m\033[36mPress Enter to continue...\033[0m" << std::endl;;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string s;
    std::getline(std::cin, s);
    system("clear");
}

int PhoneBook::add_contact(size_t index, std::string info[5])
{
    int res;

    res=_contacts[index].setFirstName(info[0]);
    res+=_contacts[index].setLastName(info[1]);
    res+=_contacts[index].setNickname(info[2]);
    res+=_contacts[index].setPhoneNumber(info[3]);
    res+=_contacts[index].setDarkSecret(info[4]);
    return(res);
}

std::string PhoneBook::add_contacts(void)
{
    std::string contact_info[5];

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << std::endl;
    std::cout << "|----------------* \033[33mNEW CONTACT\033[0m*-----------------|" << std::endl;
    std::cout << "|-----------------------------------------------|" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl << " *   First Name >> ";
    std::getline(std::cin, contact_info[0]);
    std::cout << std::endl << " *    Last Name >> ";
    std::getline(std::cin, contact_info[1]);
    std::cout << std::endl << " *     Nickname >> "; 
    std::getline(std::cin, contact_info[2]);
    std::cout << std::endl << " * Phone Number >> ";
    std::getline(std::cin, contact_info[3]);
    std::cout << std::endl << " *  Dark Secret >> ";
    std::getline(std::cin, contact_info[4]);
    std::cout << std::endl;
    system("clear");
    for (size_t i = 0; i < 5; i++)
    {
        if (contact_info[i].empty())
            return("\033[31mAt least one field has been left empty. Try again.\033[0m");;
    }
    if (!add_contact(_next_index, contact_info))
    {
        if (++_next_index == MAX_CONTACTS)
            _next_index = 0;
        if (_book_size++ >= MAX_CONTACTS)
            _book_size = MAX_CONTACTS;
        return("\033[32mNew Contact added succesfully.\033[0m");
    }
    else
        return("\033[31mNo contact added. Try again.\033[0m");
}

void PhoneBook::print_contacts(void)
{  
    std::string select;
    int         sel_nb;

    if (!_book_size)
    {
        std::cout << "\033[31mNo contacts to display. Add at least one contact.\033[0m";
        return;
    } 
    std::cout << std::endl;
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << "|---------------* \033[33mCONTACT SELECTION \033[0m*---------------|" << std::endl;
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << std::right; // Set alignment to right
    std::cout << "| " << std::setw(10) << "Index" << " | " << std::setw(10) << "Name" << " | " << std::setw(10) 
              << "Last Name" << " | " << std::setw(10) << "Nickname" << " |" << std::endl;
    std::cout << "|---------------------------------------------------|" << std::endl;
    for (size_t i = 0; i < _book_size; i++)
    {
            std::cout << "| " << "\033[31m" << std::setw(10) << i + 1 << "\033[0m";
            std::cout << " | " << std::setw(10) << format_view_str(_contacts[i].getFirstName(), 10);
            std::cout << " | " << std::setw(10) << format_view_str(_contacts[i].getLastName(), 10);
            std::cout << " | " << std::setw(10) << format_view_str(_contacts[i].getNickname(), 10);
	        std::cout << " |"<<std::endl;
    }
    std::cout << "+---------------------------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Select contact by index number >> ";
    std::cin >> select;
    sel_nb = atoi(select.c_str());
    if (sel_nb && sel_nb <= int(_book_size))
        print_contact(--sel_nb);
    else
    {
        system("clear");
        std::cout << "\033[31mWrong number. It's not rocket science...\033[0m";
    }
}

void PhoneBook::print_contact(int i)
{
    system("clear");
    std::cout << "|-----------------* \033[33mINDEX NUMBER " << i + 1 << " \033[0m*-----------------|" << std::endl;
    std::cout << "|----------------------------------------------------|" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[0m * First Name   >> \033[34m" << _contacts[i].getFirstName() << std::endl;
    std::cout << "\033[0m * Last Name    >> \033[34m" << _contacts[i].getLastName() << std::endl;
    std::cout << "\033[0m * Nickname     >> \033[34m" << _contacts[i].getNickname() << std::endl; 
    std::cout << "\033[0m * Phone Number >> \033[34m" << _contacts[i].getPhoneNumber() << std::endl;
    std::cout << "\033[0m * Dark Secret  >> \033[34m" << _contacts[i].getDarkSecret() << std::endl;
    std::cout << "\033[0m"<< std::endl;
    pause();
}
