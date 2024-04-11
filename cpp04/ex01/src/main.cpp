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

int main()
{
std::cout << " ++++ SUBJECT MAIN ++++ " << std::endl;    
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;
std::cout << " ++++++++++++++++++++++ " << std::endl;
std::cout << " +++ SUGGESTED MAIN +++ " << std::endl;
const int size = 10; // Tamaño total del array
Animal* animals[size];

for (int i = 0; i < (size / 2); ++i) 
  animals[i] = new Dog();
*animals[4] = *animals[3];
for (int i = size / 2; i < size - 1; ++i) 
  animals[i] = new Cat();
if (Cat* cat = dynamic_cast<Cat*>(animals[8])) 
  animals[9] = new Cat(*cat);
else
  animals[9] = new Cat();
for (int i = 0; i < size; ++i)
{ 
  std::cout << "animals[" << i << "]";
  animals[i]->makeSound();
}
std::cout << "*********************" << std::endl;
for (int i = 0; i < size; ++i)
{
  std::cout << "Borrado de animals[" << i << "]"<< std::endl;
  delete animals[i];
  std::cout << "*********************" << std::endl;
}

//system("leaks brains");
return 0;
}
