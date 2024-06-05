/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:55:25 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 00:55:27 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define MAX_GRADE 1
# define MIN_GRADE 150

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string& name, unsigned int const grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName(void) const;
        unsigned int getGrade(void) const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw(); 

        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw(); 

        };

    private:
        const std::string     _name;
        unsigned int          _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
