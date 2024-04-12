/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:13:39 by javi              #+#    #+#             */
/*   Updated: 2024/04/12 20:13:44 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# include <iostream>
# include <string>

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        ~MateriaSource();

        MateriaSource& operator=(const MateriaSource& other);

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);

    private:
        AMateria* _templates[4];
};

#endif
