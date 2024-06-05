/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:58:46 by javi              #+#    #+#             */
/*   Updated: 2024/04/15 11:58:48 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

 struct s_Data
    {
        int data;
    };

class Serializer
{
    public:
        static uintptr_t serialize(s_Data* ptr);
        static s_Data* deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();

        Serializer& operator=(const Serializer& other);
};

#endif
