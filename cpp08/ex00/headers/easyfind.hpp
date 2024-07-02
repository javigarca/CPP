/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:57:53 by javi              #+#    #+#             */
/*   Updated: 2024/06/29 18:57:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
bool easyfind(T & container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return true;
    return false;
}

#endif
