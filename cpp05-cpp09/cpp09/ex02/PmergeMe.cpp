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
    double elapsed = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000000.0); //실행시간을 마이크로 초단위로 얻기위해서 "CLOCKS_PER_SEC / 1000000.0"를 사용함. 그후 double형으로 형변환하면 정확한 소수점 얻을수있음
    vecTime = elapsed;
    start = std::clock();
    PmergeMe::runcontainer(Dcontainer);
    end = std::clock();
    elapsed = static_cast<double> (end - start) / (CLOCKS_PER_SEC / 1000000.0);
    deqTime = elapsed;

}

void printresult(std::vector<int> &Vec)
{

    static int i = 0;

    if (!i)
        std::cout << "Befor : " ;
    else
        std::cout << "After : ";

    for (std::vector<int>::const_iterator Vit = Vec.begin(); Vit != Vec.end(); ++Vit)
		std::cout << *Vit << " ";
    std::cout << std::endl;

    i++;
}

int midPoint(int start, int end)
{
    return(start + (end - start) / 2);
}
