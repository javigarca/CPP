/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:04:07 by javi              #+#    #+#             */
/*   Updated: 2024/03/28 12:04:12 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "resources.hpp"
# include "Contact.hpp"
# define MAX_CONTACTS 8

class PhoneBook
{

public:
        PhoneBook(void);
        ~PhoneBook(void);

        std::string add_contacts(void);
        int add_contact(size_t index, std::string info[5]);
        void print_contacts(void);
        void print_contact(int i);

private:
        size_t _book_size;
        size_t _next_index;
        Contact _contacts[MAX_CONTACTS]; 
};

#endif
