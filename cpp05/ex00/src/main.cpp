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

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat A;
    Bureaucrat B("John", 23);
    std::cout << "Two new sla...bureaucrats:" << std::endl;
    std::cout << A;
    std::cout << B;
    Bureaucrat C("James", 1);
    Bureaucrat D("Johnathan", 150);
    std::cout << "And two more, top and bottom:" << std::endl;
    std::cout << C;
    std::cout << D;
    std::cout << "Let's try one above the 1 level:" << std::endl;
    try
    {
       Bureaucrat E("Jimmy", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Now one under level 150:" << std::endl;
    try
    {
        Bureaucrat F("June", 180);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Some increment, good and not possible:" << std::endl;
    try
    {
        B.incrementGrade();
        C.incrementGrade();
        std::cout << C;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "John should be level 22:" << std::endl;
    std::cout << B;
    std::cout << "And now some decrement, good and not possible also:" << std::endl;
    try
    {
        B.decrementGrade();
        D.decrementGrade();
        std::cout << D;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Sorry John, demoted back to 23:" << std::endl;
    std::cout << B;
    std::cout << "Let's copy the newbie guy:" << std::endl;
    Bureaucrat Z(A);
    std::cout << Z;
    std::cout << "Let's assign Johnatan, level 150, to John, level 23:" << std::endl;
    B = D;
    std::cout << "Should assign level 150 to John, but the name is const!" << std::endl;
    std::cout << B;
    std::cout << "That's all folks!" << std::endl;
}
