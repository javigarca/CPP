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
    Zombie* heapzombie;
    
    heapzombie = newZombie("heap");
    heapzombie->anounce();
    delete heapzombie;

    randomChump();
    return(0);
}
