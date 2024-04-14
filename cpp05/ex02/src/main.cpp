/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:53:51 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 00:53:55 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat A("James", 1);
    Bureaucrat B("John", 23);
    std::cout << "James and John are here:" << std::endl;
    std::cout << A;
    std::cout << B;
    std::cout << "New Form produced:" << std::endl;
    PresidentialPardonForm Presi("Freddy");
    std::cout << Presi;
    std::cout << "Now James tries to execute it" << std::endl;
    A.executeForm(Presi);
    std::cout << "John tries to sign and execute" << std::endl;
    B.signForm(Presi);
    B.executeForm(Presi);
    std::cout << "Now James can execute" << std::endl;
    A.executeForm(Presi);
    /*
    std::cout << "Now let's play with constructors:" << std::endl;
    std::cout << "DEF" << std::endl;
    AForm ls;
    std::cout << ls;
    std::cout << "COPY from DEF" << std::endl;
    AForm copy(ls);
    std::cout << copy;
    std::cout << "Now assignment to COPY from st, this one that is signed" << std::endl;
    copy = st;
    std::cout << copy;
    */
    std::cout << "That's all folks!" << std::endl;
}
