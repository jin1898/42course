#include "PmergeMe.hpp"
//--occf-start-
PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other) {
        return *this;
    }
    return *this;
};
PmergeMe::PmergeMe(const PmergeMe& other){(void)(other);};
//--occf-end-

void caluclateTime(std::vector<int> &Vcontainer, std::deque<int> &Dcontainer,double &vecTime, double &deqTime)
{
    std::clock_t start = std::clock();
    PmergeMe::runcontainer(Vcontainer);
    std::clock_t end = std::clock();
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0);
    vecTime = elapsed;
    start = std::clock();
    PmergeMe::runcontainer(Dcontainer);
    end = std::clock();
    elapsed = static_cast<double> (end - start) / (CLOCKS_PER_SEC / 1000000.0);
    deqTime = elapsed;

}

void print(std::vector<int> &Vec, std::deque<int> &Deq)
{

    static int i = 0;

    if (!i)
        std::cout << "Vector "  << "befor : " ;
    else
        std::cout << "Vector "<< "after : ";

    for (std::vector<int>::const_iterator Vit = Vec.begin(); Vit != Vec.end(); ++Vit)
		std::cout << *Vit << " ";
    std::cout << std::endl;

    if (!i)
        std::cout << "Deque " << " befor : "  ;
    else
        std::cout << "Deque "  << " after : ";

    for (std::deque<int>::const_iterator Dit = Deq.begin(); Dit != Deq.end(); ++Dit)
		std::cout << *Dit << " ";
    std::cout << std::endl;
    i++;
}

int midPoint(int start, int end)
{
    return(start + (end - start) / 2);
}
