/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:46:21 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 13:46:22 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default"), _retired_materias(NULL)
{
    for (int i = 0; i <4; i++)
        this->_inventory[i] = NULL;
    std::cout << "[Character] << Def Constructor >>" << std::endl;
}

Character::Character(const std::string& name) : _name(name), _retired_materias(NULL)
{
    for (int i = 0; i <4; i++)
        this->_inventory[i] = NULL;
    std::cout << "[Character] << Parametric Constructor >>" << std::endl;
}

Character::Character(const Character& other) : _retired_materias(NULL)
{
    for (int i = 0; i <4; i++)
    {
        this->_inventory[i] = other._inventory[i]->clone();
    }
    std::cout << "[Character] << Copy Constructor >>" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        if (this->_inventory[i])
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    Node* current = _retired_materias;
    while (current != NULL)
    {
        Node* next = current->next; // Guardar el puntero al siguiente nodo
        if (current->data)
        {
            delete current->data;
            current->data = NULL;  // Again, not necessary, but clear
        }       // Eliminar el objeto Materia
        delete current;             // Eliminar el nodo actual
        current = next;             // Moverse al siguiente nodo
    }
    std::cout << "[Character] << Destructor >>" << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            delete this->_inventory[i];
            if (other._inventory[i] != NULL)
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    std::cout << "[Character] << Copy Assignment Operator >>" << std::endl;
    this->_retired_materias = NULL;
    return *this;
}

const std::string&	Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    std::cout << "Trying to equip materia: " << m->getType() << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << "Equiped materia!!!!" << std::endl;
            return;
        }
    std::cout << "Inventory full, unequip some Materia first." << std::endl;
}

void Character::unequip(int idx)
{
    std::cout << "Attempting to unequip slot:" << idx << std::endl;
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
    {
        Node* newNode = new Node(this->_inventory[idx]);
        newNode->next = _retired_materias;
        _retired_materias = newNode;
        std::cout << "Unequip materia: " << this->_inventory[idx]->getType() << std::endl;
        this->_inventory[idx] = NULL;
    }
    else
        std::cout << "Nothing to unequip there." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    std::cout << "Attempting to use materia at slot " << idx << std::endl;
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
        this->_inventory[idx]->use(target);
    else
        std::cout << "Take a moment to rethink what you're doing." << std::endl;
}
