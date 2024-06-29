/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:02:31 by javi              #+#    #+#             */
/*   Updated: 2024/04/15 12:03:02 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inter.hpp"

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <typename P>
void print(P const & n)
{
    std::cout << n << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
	std::string array[] = {"uno","dos", "cincuenta"};
    char arrayChar[6] = {'K', 'I', 'L', 'L', 'M', 'E'};
    Awesome tab2[7];
    int len1 = sizeof(arr) / sizeof(arr[0]);
    int len2 = sizeof(array) / sizeof(array[0]);

    iter(arr, len1, print<int>);
    iter(array, len2, print<std::string>);
	iter(arrayChar, 6, print<char>);
	iter(tab2, 7, print<Awesome>);

    return 0;
}

