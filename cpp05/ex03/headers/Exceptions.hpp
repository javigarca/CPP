/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:40:37 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 20:40:39 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

# include <exception>

class GradeTooHighException : public std::exception
{
    public:
       virtual const char* what() const throw()
       {
        return (" [*] Exception [*] >> Grade exceedes the top level.");
       } 
};

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return (" [*] Exception [*] >> Grade doesn't reach the bare minimun.");
        }
};

class SignedFormException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return (" [*] Exception [*] >> Form already signed.");
        }
};

class NotSignedFormException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return (" [*] Exception [*] >> Unable to execute. Form not signed. ");
        }
};

class FormNotAvailableException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return (" [*] Exception [*] >> The requested form doesn't exist. ");
        }
};

#endif
