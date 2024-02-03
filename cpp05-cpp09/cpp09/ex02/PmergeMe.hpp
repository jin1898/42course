#ifndef P_HPP
#define P_HPP

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>


#define START(x) x + 1

class PmergeMe
{

public:

    //Orthodox Canonical Form
    PmergeMe();
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    PmergeMe(const PmergeMe& other);

    //Vector sort functions
    template <typename T>
    static void mergeInsertSortVector(T &container, int start, int end)
    {
        int newEnd;
        if (start < end)
        {
            if ((end - start) < 10)
                insertSortVector(container, start, end);
            else
            {
                newEnd = start + (end - start) / 2;
                mergeInsertSortVector(container,  start, newEnd);
                mergeInsertSortVector(container, START(newEnd), end);
                mergeSortVector(container, start, newEnd, end);
            }
        }
    };
    template <typename T>
    static void mergeSortVector(T &container, int start, int mid, int end)
    {
        int i, j , k;

        std::vector<int> left(mid - start + 1);
        std::vector<int> right(end - mid);

        for(i = 0; i < (mid - start + 1); ++i)
            left[i] = container[start + i];
        for(j = 0; j < (end - mid); ++j)
            right[j] = container[mid + 1 + j];
        i = 0;
        j = 0;
        k = start;
    while(i < (mid - start + 1) && j < (end - mid))
    {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while(i < (mid - start + 1))
        container[k++] =  left[i++];
    while (j < (end - mid))
        container[k++] = right[j++];
};
    template <typename T>
    static void insertSortVector(T &container, int start, int end)
    {
        for(int index = START(start); index <= end; index++)
        {
            int hold = container[index];
            int j = index - 1;
            for(; j >= start && container[j] > hold; --j)
                container[j + 1] = container[j];
            container[j + 1] = hold;
        }
    };
    //Calcualte time functions
    template <typename T>
    static void runcontainer(T &container)
    {
       mergeInsertSortVector(container, 0, container.size() - 1);
    };
    // static void runDeque(std::deque<int> &container);
};

// Utility functions
void print(std::vector<int> &, std::deque<int> &);
void caluclateTime(std::vector<int> &, std::deque <int> &, double &, double &);
int midPoint(int start, int end);

#endif
