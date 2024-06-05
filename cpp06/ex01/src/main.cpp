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

int main()
{
    s_Data randata;
    randata.data = 65;
    s_Data *desdata;
    uintptr_t ranptr;

    std::cout << "Original Data: " << randata.data << std::endl;
    std::cout << "Original Memo: " << &randata.data << std::endl;
    
    ranptr = Serializer::serialize(&randata);
    std::cout << "new pointer data: " << ranptr << std::endl;
    std::cout << "new pointer memo: " << &ranptr << std::endl;
    desdata = Serializer::deserialize(ranptr);
    std::cout << "Des Data: " << desdata->data << std::endl;
    std::cout << "Des memo: " << &desdata->data << std::endl;

    return 0;
}
