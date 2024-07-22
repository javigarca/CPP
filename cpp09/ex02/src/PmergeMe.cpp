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

#include "../headers/PmergeMe.hpp"

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
    fordJohnsonSort(this->_vector, 0, getVectorSize() - 1);
    return;
}

void PmergeMe::sortDeque()
{
    fordJohnsonSort_d(this->_deque, 0, getDequeSize() - 1);
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

/*
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
*/
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
/*
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
*/
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

/*
### `fordJohnsonSort` Function

1. **Base Case (Line 3)**: The function checks if the `left` index is less than the `right` index. If not, it means there's only one element, and no sorting is needed.
   
2. **Size Check (Line 5)**: It calculates the size of the current section of the array. If the size is 2 or less:
   - **Swap (Line 7)**: If there are two elements and they are out of order, swap them.

3. **Divide and Conquer (Lines 12-15)**: If the size is more than 2:
   - **Calculate Middle (Line 13)**: It finds the middle index to split the array into two halves.
   - **Recursively Sort Left Half (Line 14)**: It calls itself to sort the left half.
   - **Recursively Sort Right Half (Line 15)**: It calls itself to sort the right half.

4. **Merge (Line 17)**: After sorting both halves, it merges them together in sorted order using the `merge` function.

### `merge` Function

1. **Calculate Sizes (Lines 21-22)**: It calculates the sizes of the two subarrays to be merged.

2. **Create Temporary Arrays (Lines 24-25)**: It creates two temporary arrays to hold the left and right subarrays.

3. **Copy Data (Lines 27-30)**: It copies the data from the main array to the temporary left and right subarrays.

4. **Merge Process (Lines 32-47)**:
   - **Indices Initialization (Line 32)**: Initializes indices for left subarray (`i`), right subarray (`j`), and merged array (`k`).
   - **Compare and Merge (Lines 34-42)**: Compares elements of the left and right subarrays and puts the smaller element into the main array.
   - **Copy Remaining Elements of Left Subarray (Lines 44-47)**: If there are any elements left in the left subarray, they are copied to the main array.
   - **Copy Remaining Elements of Right Subarray (Lines 49-52)**: If there are any elements left in the right subarray, they are copied to the main array.

### Simplified Step-by-Step Explanation

1. **Initial Call**: You call `fordJohnsonSort` with the entire array. It checks if the array can be split.

2. **Splitting**: The array is split into two halves recursively until each subarray has at most 2 elements.

3. **Sorting Small Subarrays**: If a subarray has 2 elements, they are swapped if needed to ensure they are in order.

4. **Merging**: The sorted subarrays are merged together to form larger sorted subarrays, eventually resulting in a completely sorted array.

### Visual Example

Imagine you have an array `[5, 2, 9, 1, 5, 6]`:

1. Split into `[5, 2, 9]` and `[1, 5, 6]`.
2. Further split into `[5, 2]`, `[9]`, `[1, 5]`, and `[6]`.
3. Sort small parts:
   - `[5, 2]` becomes `[2, 5]`.
   - `[1, 5]` is already sorted.
4. Merge back:
   - `[2, 5]` and `[9]` merge to `[2, 5, 9]`.
   - `[1, 5]` and `[6]` merge to `[1, 5, 6]`.
5. Finally merge `[2, 5, 9]` and `[1, 5, 6]` to get `[1, 2, 5, 5, 6, 9]`.

That's the essence of the `fordJohnsonSort` function and how it sorts the array using the divide-and-conquer approach and merging.
*/