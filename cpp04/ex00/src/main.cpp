/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:50:01 by javi              #+#    #+#             */
/*   Updated: 2024/04/10 19:50:03 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    
    Cat cat;
    Dog dog;
    WrongCat wcat;

    std::cout << "A cat is a " << cat.getType() << "." << std::endl;
    std::cout << "A dog is a " << dog.getType() << "." << std::endl;
    std::cout << "A wrogncat is a " << wcat.getType() << "." << std::endl;

    std::cout << "The cat goes: " << std::endl;
    cat.makeSound();
    std::cout << "The dog goes: " << std::endl;
    dog.makeSound();
    std::cout << "The wrongcat goes: " << std::endl;
    wcat.makeSound();

    std::cout << "******** FROM THE SUBJECT ********" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* w = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << w->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    w->makeSound();

    delete meta;
    delete i;
    delete j;
    delete w;
    //system("leaks animals");
    return 0;
}
