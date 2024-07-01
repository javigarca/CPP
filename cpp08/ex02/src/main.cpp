/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:02:31 by javi              #+#    #+#             */
/*   Updated: 2024/07/01 10:44:00 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Complex.hpp"
#include "Array.hpp"

int main()
{
   try
    {
        Array<int> arr1(5); // Crear un array de tamaño 5
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;
        arr1[3] = 4;
        arr1[4] = 5;

        Array<int> arr2(arr1); // Usar el constructor de copia

        for (unsigned int i = 0; i < arr2.size(); ++i)
        {
            std::cout << arr2[i] << std::endl;
        }

        Array<int> arr3; 
        arr3 = arr1; 

        for (unsigned int i = 0; i < arr3.size(); ++i)
        {
            std::cout << arr3[i] << std::endl;
        }

        // exception
        std::cout << arr1[5] << std::endl;
    }
    catch (const Array<int>::OutOfBoundsException& e)
    {
        std::cerr << e.what() << std::endl;
    }

   try
    {
        Array<Complex> arr1(3); // Crear un array de tamaño 3
        arr1[0] = Complex(1.0, 2.0);
        arr1[1] = Complex(3.0, 4.0);
        arr1[2] = Complex(5.0, 6.0);

        Array<Complex> arr2(arr1); // Usar el constructor de copia

        std::cout << "arr2 (copied from arr1):" << std::endl;
        for (unsigned int i = 0; i < arr2.size(); ++i)
        {
            std::cout << arr2[i] << std::endl;
        }

        Array<Complex> arr3; // Crear un array vacío
        arr3 = arr1; // Usar el operador de asignación

        std::cout << "arr3 (assigned from arr1):" << std::endl;
        for (unsigned int i = 0; i < arr3.size(); ++i)
        {
            std::cout << arr3[i] << std::endl;
        }

        // Intentionally accessing out of bounds to trigger the exception
        std::cout << arr1[3] << std::endl;
    }
    catch (const Array<Complex>::OutOfBoundsException& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

