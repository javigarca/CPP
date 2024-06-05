/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:02:31 by javi              #+#    #+#             */
/*   Updated: 2024/04/15 12:03:02 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Test.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    std::srand(std::time(0)); 
    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            std::cout << "Generated A Class" << std::endl; 
            return new A();
        case 1: 
            std::cout << "Generated B Class" << std::endl;
            return new B();
        case 2: 
            std::cout << "Generated C Class" << std::endl;
            return new C();
        default:
            std::cout << "Randomization error. Report to javigarc" << std::endl;
            return (NULL);
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "By pointer, an A class" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "By pointer, a B class" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "By pointer, an C class" << std::endl;
    else
        std::cout << "Unknown class for pointer" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "By ref, an A class" << std::endl;
        return;
    }
    catch(std::exception& e)
    {}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "By ref, an B class" << std::endl;
        return;
    }
    catch(std::exception& e)
    {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "By ref, an C class" << std::endl;
        return;
    }
    catch(std::exception& e)
    {
        std::cout << "Unknown class for reference" << std::endl;
    }
}

int main()
{
    Base* ptr = generate();
    Test* wrong = new Test();
    identify(*ptr);
    identify(ptr);    

    std::cout << "Testing a derivate class not A, not B, not C" << std::endl;
    identify(*wrong);
    identify(wrong);
    
    delete ptr;
    delete wrong;
    return 0;
}

