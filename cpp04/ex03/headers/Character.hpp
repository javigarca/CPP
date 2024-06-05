/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:02:21 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 13:02:24 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

struct Node {
    AMateria* data;
    Node* next;
    Node(AMateria* m) : data(m), next(NULL) {}
};

class Character : public ICharacter
{
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        ~Character();

        Character& operator=(const Character& other);

        const std::string&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
    
    private:
        std::string _name;
        AMateria* _inventory[4];
        Node* _retired_materias;
};

#endif
