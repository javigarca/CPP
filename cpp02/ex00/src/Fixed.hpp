/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:31:19 by javi              #+#    #+#             */
/*   Updated: 2024/04/07 21:31:23 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
    public:
        Fixed();
        Fixed Fixed(Fixed oldfixed);
        Fixed operator =();
        ~Fixed();

    private:
        int                 _number_value;
        static const int    _fractional_bits = 8;
};