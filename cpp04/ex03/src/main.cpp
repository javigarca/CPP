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

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "-----Testing limits of MateriaSource Stack-----\n\n\n";

	for (int i = 0; i < 5; i++)
  {
    std::cout << "***" << i << "***" << std::endl;
		src->learnMateria(new Ice());
  }

	std::cout << "-----Testing unknown materia-----\n\n\n";

	src->createMateria("Rock");

	std::cout << "-----Creating a Character-----\n\n\n";

	ICharacter* me = new Character("me");
	AMateria* tmp;
  std::cout << "-----ICE-----\n\n\n";
	tmp = src->createMateria("ice");
	me->equip(tmp);
  std::cout << "-----CURE-----\n\n\n";
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
  std::cout << "-----ICE a BOB-----\n\n\n";
	me->use(0, *bob);
  std::cout << "-----CURE a BOB-----\n\n\n";
	me->use(1, *bob);

   me->unequip(0);
   me->use(0, *bob);

	me->equip(src->createMateria("ice"));

	delete bob;
	delete me;
	delete src;
  //system("leaks recap");
	return 0;
}
