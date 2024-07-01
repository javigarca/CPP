/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:02:01 by javi              #+#    #+#             */
/*   Updated: 2024/07/01 11:02:45 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
    
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        ~Array();

        Array& operator=(Array const &other);
        T& operator[](unsigned int idx);

        unsigned int size() const;

        class OutOfBoundsException : public std::exception
            {
                public:
                    const char* what() const throw()
                    {
                        return "Index out of bounds";
                    }
            };
    
    private:
        T               *_array;
        unsigned int    _size;

};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    if (n > 0) 
        _array = new T[n];
    else
        _array = NULL;
}

template <typename T>
Array<T>::~Array()
{
    delete [] _array;
}

template <typename T>
Array<T>::Array(Array const &other) : _size(other._size)
{
    if (other._size == 0)
        this->_array = NULL;
    else
    {
        this->_array  = new T[other._size];
        for (unsigned int i = 0; i < other._size ; i++)
            this->_array[i] = other._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        delete [] this->_array;
        if (other._size > 0)
        {
            this->_array  = new T[other._size];
            for (unsigned int i = 0; i < other._size ; i++)
                this->_array[i] = other._array[i];
        }
        else
            this->_array = NULL;
        this->_size = other._size;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx >= this->_size)
        throw OutOfBoundsException();
    return this->_array[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}


#endif