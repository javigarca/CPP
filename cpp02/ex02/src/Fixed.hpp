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
# include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& original);
        Fixed(const int from_integer);
        Fixed(const float from_float);
        ~Fixed();

        Fixed&  operator=(const Fixed& original);
        bool    operator==(const Fixed& otherfix) const;
        bool    operator!=(const Fixed& otherfix) const;
        bool    operator<=(const Fixed& otherfix) const;
        bool    operator>=(const Fixed& otherfix) const;
        bool    operator<(const Fixed& otherfix) const;
        bool    operator>(const Fixed& otherfix) const;
        Fixed   operator+(const Fixed& otherfix) const;
        Fixed   operator-(const Fixed& otherfix) const;
        Fixed   operator/(const Fixed& otherfix) const;
        Fixed   operator*(const Fixed& otherfix) const;
        Fixed&  operator++(void);
        Fixed&  operator--(void);
        Fixed   operator++(int);
        Fixed   operator--(int);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        
        static Fixed&  min(Fixed& a, Fixed& b);
        static const Fixed&  min(const Fixed& a, const Fixed& b);
        static Fixed&  max(Fixed& a, Fixed& b);
        static const Fixed&  max(const Fixed& a, const Fixed& b);

    private:
        int                 _number_value;
        static const int    _fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
