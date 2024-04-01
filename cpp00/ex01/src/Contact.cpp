/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:47:04 by javi              #+#    #+#             */
/*   Updated: 2024/03/28 11:47:07 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "resources.hpp"
#include "Contact.hpp"

Contact::Contact()
{}
Contact::~Contact()
{}
Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string d) : _first_name(f), _last_name(l), _nickname(n), _phone_number(p), _dark_secret(d)
{}
Contact::Contact(std::string info[5]) : _first_name(info[0]), _last_name(info[1]), _nickname(info[2]), _phone_number(info[3]), _dark_secret(info[4])
{}

int Contact::setFirstName(std::string firstname)
{
    this->_first_name = firstname;
    return(0);
}
int Contact::setLastName(std::string lastname)
{
    this->_last_name = lastname;
    return(0);
}
int Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
    return(0);
}
int Contact::setPhoneNumber(std::string phonenumber)
{
    this->_phone_number = phonenumber;
    return(0);
}
int Contact::setDarkSecret(std::string darksecret)
{
    this->_dark_secret = darksecret;
    return(0);
}
const std::string Contact::getFirstName(void) const
{
    return(this->_first_name);
}
const std::string Contact::getLastName(void) const
{
    return(this->_last_name);
}
const std::string Contact::getNickname(void) const
{
    return(this->_nickname);
}
const std::string Contact::getPhoneNumber(void) const
{
    return(this->_phone_number);
}
const std::string Contact::getDarkSecret(void) const
{
    return(this->_dark_secret);
}
