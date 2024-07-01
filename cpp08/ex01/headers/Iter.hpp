/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:57:53 by javi              #+#    #+#             */
/*   Updated: 2024/06/29 18:57:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* array, int len, F (func))
{
    if (len < 1)
    {
        std::cout << "Empty array" << std::endl;
        return;
    }
    for (int i = 0; i < len; i++)
    {
        func(array[i]);
    }
    
}

#endif
