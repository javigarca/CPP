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
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
    std::cout << "************************** ROBOTOMIZTIONS!!" << std::endl;
    Bureaucrat C("Rick", 1);
    Bureaucrat D("Jason", 73);
    std::cout << "Rick and Jason for this one:" << std::endl;
    std::cout << C;
    std::cout << D;
    std::cout << "New Form produced, poor guy Spud:" << std::endl;
    RobotomyRequestForm robot("Spud");
    std::cout << robot;
    std::cout << "Now Rick tries to execute it" << std::endl;
    C.executeForm(robot);
    std::cout << "Jason tries to sign and execute" << std::endl;
    D.signForm(robot);
    D.executeForm(robot);
    std::cout << "Now Rick signs" << std::endl;
    C.signForm(robot);
    std::cout << "Jason tries to sign and execute, again!" << std::endl;
    D.signForm(robot);
    D.executeForm(robot);
    std::cout << "Rick would execute it 5 times" << std::endl;
    for (int i = 0; i < 5; i++)
        C.executeForm(robot);
    std::cout << "************************** TREEEEEES!!" << std::endl;
    Bureaucrat Z;
    std::cout << C.getName() << "and " << Z.getName() << " for gardening:" << std::endl;
    std::cout << C;
    std::cout << Z;
    std::cout << "New Form produced:" << std::endl;
    ShrubberyCreationForm tree("nice");
    std::cout << tree;
    std::cout << "Now Rick tries to execute it" << std::endl;
    C.executeForm(tree);
    std::cout << Z.getName() << " tries to sign and execute" << std::endl;
    Z.signForm(tree);
    Z.executeForm(tree);
    std::cout << "Now Rick signs" << std::endl;
    C.signForm(tree);
    std::cout <<  Z.getName() << " tries to sign and execute, again!" << std::endl;
    Z.signForm(tree);
    Z.executeForm(tree);
    std::cout << C.getName() << " would execute it" << std::endl;
    C.executeForm(tree);
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
    std::cout << "**************************************" << std::endl;
    std::cout << "That's all folks!" << std::endl;
}
