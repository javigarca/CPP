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
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();

delete j;//should not create a leak
delete i;
std::cout << " ++++++++++++++++++++++ " << std::endl;
std::cout << " +++ SUGGESTED MAIN +++ " << std::endl;
const int size = 10; // Tamaño total del array
AAnimal* AAnimals[size];

for (int i = 0; i < (size / 2); ++i) 
  AAnimals[i] = new Dog();
*AAnimals[4] = *AAnimals[3];
for (int i = size / 2; i < size - 1; ++i) 
  AAnimals[i] = new Cat();
if (Cat* cat = dynamic_cast<Cat*>(AAnimals[8])) 
  AAnimals[9] = new Cat(*cat);
else
  AAnimals[9] = new Cat();
for (int i = 0; i < size; ++i)
{ 
  std::cout << "AAnimals[" << i << "]";
  AAnimals[i]->makeSound();
}
std::cout << "*********************" << std::endl;
for (int i = 0; i < size; ++i)
{
  std::cout << "Borrado de AAnimals[" << i << "]"<< std::endl;
  delete AAnimals[i];
  std::cout << "*********************" << std::endl;
}
//AAnimal* abstract = new AAnimal();
//system("leaks abstract");
return 0;
}
