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
#include "Form.hpp"

int main(void)
{
    Bureaucrat A("James", 1);
    Bureaucrat B("John", 23);
    std::cout << "James and John are here:" << std::endl;
    std::cout << A;
    std::cout << B;
    std::cout << "New Form produced:" << std::endl;
    Form st("SuperTop", 15, 20);
    std::cout << st;
    std::cout << "First John tries to sign:" << std::endl;
    B.signForm(st);
    std::cout << "Now James would do it" << std::endl;
    A.signForm(st);
    std::cout << "Now let's play with constructors:" << std::endl;
    std::cout << "DEF" << std::endl;
    Form ls;
    std::cout << ls;
    std::cout << "COPY from DEF" << std::endl;
    Form copy(ls);
    std::cout << copy;
    std::cout << "Now assignment to COPY from st, this one that is signed" << std::endl;
    copy = st;
    std::cout << copy;
    std::cout << "That's all folks!" << std::endl;
}
