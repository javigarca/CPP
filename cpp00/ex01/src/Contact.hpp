/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:03:47 by javi              #+#    #+#             */
/*   Updated: 2024/03/28 12:03:49 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "resources.hpp"

class Contact
{
    public:
            Contact();
            Contact(std::string f, std::string l, std::string n, std::string p, std::string d);
            Contact(std::string info[5]);
            ~Contact(void);

            int setFirstName(std::string firstname);
            int setLastName(std::string lastname);
            int setNickname(std::string nickname);
            int setPhoneNumber(std::string phonenumber);
            int setDarkSecret(std::string darksecret);

            const std::string getFirstName(void) const;
            const std::string getLastName(void) const;
            const std::string getNickname(void) const;
            const std::string getPhoneNumber(void) const;
            const std::string getDarkSecret(void) const;
            
    private:
            std::string _first_name;
            std::string _last_name;
            std::string _nickname;
            std::string _phone_number;
            std::string _dark_secret;
};

#endif
