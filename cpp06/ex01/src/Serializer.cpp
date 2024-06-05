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

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer Constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& copy) {
	if (this != &copy) {
		*this = copy;
	}
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other) {
		return *this;
	}
	return *this;
}

uintptr_t Serializer::serialize(s_Data* ptr) {
	uintptr_t newuiptr = reinterpret_cast<uintptr_t>(ptr);
	return (newuiptr);
}

s_Data* Serializer::deserialize(uintptr_t raw) {
	s_Data* newData = reinterpret_cast<s_Data*>(raw);
	return (newData);
}