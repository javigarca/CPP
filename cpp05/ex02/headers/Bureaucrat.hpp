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
# include "Exceptions.hpp"

class AForm;

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

        void signForm(AForm& formtosign);

    private:
        const std::string   _name;
        unsigned int        _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
