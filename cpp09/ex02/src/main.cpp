/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:51:41 by javi              #+#    #+#             */
/*   Updated: 2024/07/05 17:51:44 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }


    PmergeMe object;
    if (object.parseInput(argc, argv))
    {
        clock_t start, end;
        double time_v, time_d;

        //object.display();
        object.display("Before");
        start = static_cast<double>(clock());
        object.sortVector();
        end = static_cast<double>(clock());
        time_v = end - start / CLOCKS_PER_SEC;
        start = static_cast<double>(clock());
        object.sortDeque();
        end = static_cast<double>(clock());
        time_d = end - start / CLOCKS_PER_SEC;
        object.display("After");
        std::cout << "Time to process a range of " << object.getVectorSize() << " elements with std::vector : " << time_v << std::endl;
        std::cout << "Time to process a range of " << object.getDequeSize() << " elements with std::deque  : " << time_d << std::endl;
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}

/*
Imagine You Have a List of Numbers

Let's say you have a list of numbers that you want to sort from smallest to largest. Here's a simple example:

12,11,13,5,6,7,3,15,8,112,11,13,5,6,7,3,15,8,1
Step-by-Step Process
Step 1: Pairwise Comparison

First, we compare the numbers in pairs. Think of it as a competition where each pair of numbers "fights," and we remember which number is smaller and which is larger.

    Compare 12 and 11: 11 is smaller, 12 is larger.
    Compare 13 and 5: 5 is smaller, 13 is larger.
    Compare 6 and 7: 6 is smaller, 7 is larger.
    Compare 3 and 15: 3 is smaller, 15 is larger.
    Compare 8 and 1: 1 is smaller, 8 is larger.

After this step, we have:

    Smaller numbers: 11, 5, 6, 3, 1
    Larger numbers: 12, 13, 7, 15, 8

Step 2: Sorting the Smaller Group

We take the smaller group of numbers (the "winners" of the pairs) and sort them. For simplicity, let's use a basic sorting method you might know, like arranging playing cards in your hand.

After sorting: 1,3,5,6,111,3,5,6,11
Step 3: Sorting the Larger Group

We do the same for the larger group of numbers (the "losers" of the pairs).

After sorting: 7,8,12,13,157,8,12,13,15
Step 4: Merging the Sorted Groups

Now, we need to combine these two sorted groups into one big sorted list. Think of it like combining two sorted stacks of playing cards into one sorted stack.

We start with the smallest number from both groups and add it to our final sorted list:

    Compare the smallest numbers from both groups: 1 (from the first group) and 7 (from the second group). 1 is smaller, so it goes first.
    Next, compare the next smallest numbers: 3 and 7. 3 is smaller, so it goes next.
    Continue this process until all numbers are added to the final list.

After merging, our final sorted list is: 1,3,5,6,7,8,11,12,13,151,3,5,6,7,8,11,12,13,15
Why This Works

The Ford-Johnson algorithm minimizes the number of comparisons needed to sort the list, making it efficient. By breaking down the list into smaller groups, sorting those groups, and then merging them, we ensure that we do not have to compare every number with every other number directly.
Summary

    Pairwise Comparison: Compare numbers in pairs and separate them into "winners" and "losers."
    Sort Each Group: Sort the smaller group of winners and the larger group of losers separately.
    Merge Sorted Groups: Combine the two sorted groups into one final sorted list.

This method efficiently organizes the list with fewer comparisons, making it a clever way to sort items!
*/
