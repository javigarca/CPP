/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:51:19 by javi              #+#    #+#             */
/*   Updated: 2024/04/13 11:51:21 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define MAX_GRADE 1
# define MIN_GRADE 150

# include <exception>
# include <iostream>
# include <string>

class Form
{
    public:
        Form();
        Form();

    private:
        const std::string _name;
};

#endif
