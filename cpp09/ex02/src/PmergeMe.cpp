/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:35:04 by javi              #+#    #+#             */
/*   Updated: 2024/07/07 16:55:35 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe::~PmergeMe()
{}

PmergeMe & PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_deque = other._deque;
        this->_vector = other._vector;
    }
    return *this;
}

bool PmergeMe::isValidNumber(const std::string& str, int& number)
{
    std::stringstream ss(str);
    ss >> number;
    // Verificar si la conversión falló o si hay caracteres adicionales en la cadena
    if (ss.fail() || !ss.eof() || number < 0)
        return false;
    return true;
}

bool PmergeMe::extractValidNumbers(const std::string& str, std::vector<int>& validNumbers)
{
    std::stringstream ss(str);
    std::string token;
    while (ss >> token)
    {
        int number;
        if (isValidNumber(token, number))
            validNumbers.push_back(number);
        else
            return false;
    }
    return true;
}

bool vectorHasDuplicates(const std::vector<int>& vec)
{
    std::set<int> seenElements;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        if (seenElements.find(*it) != seenElements.end()) {
            return true; // Se encontró un duplicado
        }
        seenElements.insert(*it);
    }
    return false; // No se encontraron duplicados
}

bool PmergeMe::parseInput(int argc, char *argv[])
{
    std::vector<int> validNumbers;
    for (int i = 1; i < argc; ++i)
    {
        if (!extractValidNumbers(argv[i], validNumbers))
            return false;
    }
        
    if (validNumbers.size() < 2 || vectorHasDuplicates(validNumbers))
        return false;
    
    std::cout << "Data validation complete. Starting sorting process." << std::endl;
    _vector = validNumbers;
    _deque.assign(_vector.begin(), _vector.end());
    return true;
}

void PmergeMe::display(const std::string &title) const
{
    std::cout << title << ": ";

    for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
        std::cout <<  *it << " ";
    std::cout << std::endl;
}

void PmergeMe::display() const
{
    std::cout << "Deque: ";

    for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); ++it)
        std::cout <<  *it << " ";
    std::cout << std::endl;
}

void PmergeMe::sortVector()
{
    std::cout << "Sorting Vector...";
    fordJohnsonSort(this->_vector, 0, getVectorSize() - 1);
    std::cout << "... end" << std::endl;
    return;
}

void PmergeMe::sortDeque()
{
    std::cout << "Sorting Deque...";
    fordJohnsonSort_d(this->_deque, 0, getDequeSize() - 1);
    std::cout << "... end" << std::endl;
    return;
}

size_t PmergeMe::getVectorSize() const
{
    return this->_vector.size();
}

size_t PmergeMe::getDequeSize() const
{
    return this->_deque.size();
}

void insertSorted(std::vector<int>& arr, int end, int element)
{
    int i = end - 1;
    while (i >= 0 && arr[i] > element)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
}

// Function to merge two sorted subarrays
void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Ford-Johnson sorting algorithm
void PmergeMe::fordJohnsonSort(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int size = right - left + 1;
        if (size <= 2)
        {
            if (arr[left] > arr[right])
                std::swap(arr[left], arr[right]);
            return;
        }
        // Initial pairwise sorting
        int mid = left + (right - left) / 2;
        fordJohnsonSort(arr, left, mid);
        fordJohnsonSort(arr, mid + 1, right);
        // Recursive merging
        merge(arr, left, mid, right);
    }
}

// Function to insert an element into a sorted subarray in a deque
void insertSorted_d(std::deque<int>& arr, int end, int element)
{
    int i = end - 1;
    while (i >= 0 && arr[i] > element)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
}

// Function to merge two sorted subarrays in a deque
void merge_d(std::deque<int>& arr, int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        } 
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Ford-Johnson sorting algorithm for deque
void PmergeMe::fordJohnsonSort_d(std::deque<int>& arr, int left, int right)
{
    if (left < right)
    {
        int size = right - left + 1;
        if (size <= 2)
        {
            if (arr[left] > arr[right])
                std::swap(arr[left], arr[right]);
            return;
        }
        // Initial pairwise sorting
        int mid = left + (right - left) / 2;
        fordJohnsonSort_d(arr, left, mid);
        fordJohnsonSort_d(arr, mid + 1, right);
        // Recursive merging
        merge_d(arr, left, mid, right);
    }
}