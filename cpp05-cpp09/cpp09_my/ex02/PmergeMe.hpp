#ifndef P_HPP
#define P_HPP

#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>

class PmergeMe
{

public:

    PmergeMe();
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    PmergeMe(const PmergeMe& other);

    template <typename T>
    static void mergeInsertSortVector(T &container, int start, int end)
    {
        int newEnd;
        if (start < end)
        {
            if ((end - start) < 10) // 범위가 적은데 mergesort를 하면 오버헤드가 발생할수있다함.
                insertSortVector(container, start, end);
            else
            {
                newEnd = start + (end - start) / 2;
                mergeInsertSortVector(container,  start, newEnd); // 반으로 나눠서 2번 marge함.
                mergeInsertSortVector(container, newEnd + 1, end);// 반으로 나눠서 2번으로 marge함.
                mergeSortVector(container, start, newEnd, end);// 그리고 그 둘을 합침
            }
        }
    };
    template <typename T>
    static void mergeSortVector(T &container, int start, int mid, int end)
    {
        int leftIndex,rightIndex,containIndex;

        std::vector<int> left(mid - start);
        std::vector<int> right(end - mid);

        for(leftIndex = 0; leftIndex < (mid - start); ++leftIndex)
            left[leftIndex] = container[start + leftIndex];
        for(rightIndex = 0; rightIndex < (end - mid); ++rightIndex)
            right[rightIndex] = container[mid + 1 + rightIndex];
        leftIndex = 0;
        rightIndex = 0;
        containIndex=start;
    while(leftIndex < (mid - start) && rightIndex < (end - mid))
    {
        if (left[leftIndex] <= right[rightIndex])
            container[containIndex++] = left[leftIndex++];
        else
            container[containIndex++] = right[rightIndex++];
    }

    while(leftIndex < (mid - start))
        container[containIndex++] =  left[leftIndex++];
    while (rightIndex < (end - mid))
        container[containIndex++] = right[rightIndex++];
};
    template <typename T>
    static void insertSortVector(T &container, int start, int end)
    {
        for(int index = start; index <= end; index++)
        {
            int pivotValue = container[index];
            int comparValue = index - 1;
            for(; comparValue >= start && container[comparValue] > pivotValue; --comparValue)
                container[comparValue + 1] = container[comparValue];
            container[comparValue + 1] = pivotValue;
        }
    };
    template <typename T>
    static void runcontainer(T &container)
    {
       mergeInsertSortVector(container, 0, container.size() - 1);//당연한말이지만 0부터 시작하니까 n개이면 n-1이 마지막이다.
    };
};

void printresult(std::vector<int> &, std::deque<int> &);
void caluclateTime(std::vector<int> &, std::deque <int> &, double &, double &);
int midPoint(int start, int end);

#endif


