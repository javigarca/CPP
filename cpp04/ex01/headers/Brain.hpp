/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:57:17 by javi              #+#    #+#             */
/*   Updated: 2024/04/11 16:57:20 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();

        Brain& operator=(const Brain& other);

    private:
        std::string ideas[100];
};

#endif
