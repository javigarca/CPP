/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:13:39 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 20:13:44 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _templates[i] = NULL;
    std::cout << "[MateriaSource] << Def Constructor >>" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) 
{
    for (int i = 0; i < 4; i++)
    {
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = NULL;
    }
    std::cout << "[MateriaSource] << Copy Constructor >>" << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _templates[i];
    std::cout << "[MateriaSource] << Destructor >>" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _templates[i]; // Limpia el recurso actual antes de asignar uno nuevo
            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
            else
                _templates[i] = NULL;
        }
    }
    std::cout << "[MateriaSource] << Copy Assignment Operator >>" << std::endl;
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << "Empty Materia. Nothing to learn." << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] == NULL)
        {
            _templates[i] = m;
            return;
        }
    }
    delete m;
    std::cout << "No more room for more Materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_templates[i] != NULL && _templates[i]->getType() == type)
        {
            std::cout << "Created materia: " << type << " en " << i << "." << std::endl;
            return _templates[i]->clone();
        }
    }
    std::cout << "This is not the Materia you are looking for." << std::endl;
    return NULL;
}
