/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:10:03 by javi              #+#    #+#             */
/*   Updated: 2024/04/02 00:10:18 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.h"

int main()
{
    int z = 10;
    Zombie* zombiehorde;
    
    zombiehorde = zombieHorde(z, "Johrde");
    for (int i = 0; i < z; i++)
           zombiehorde[i].anounce();
    delete [] zombiehorde;
    return(0);
}
