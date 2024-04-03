/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:08:53 by javi              #+#    #+#             */
/*   Updated: 2024/04/02 00:08:56 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        std::string newname = name;
        newname += "[";
        newname += std::to_string(i + 1);
        newname += "]";
        horde[i].setName(newname);
    }
    return (horde);
}
