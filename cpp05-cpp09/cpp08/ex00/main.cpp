#include "easyfind.hpp"
#include <iostream>

#include <vector>
#include <list>

static void test_vector()
{
    std::cout << "---vector-----start-" << std::endl;
    std::vector<int> test(4, 1);
    for(int i = 0; i < 4; i++)
        std::cout << test[i] << " ";
    std::cout << std::endl;
    try{easyfind(test, 9);}
    catch(std::exception & error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "---vector-----end-" << std::endl;
}

static void list_test()
{
    std::cout << "---list-----start-" << std::endl;
    std::list<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);

    for(std::list<int>::iterator it = test.begin(); it != test.end(); it++)
        std::cout << *it << " ";
    std::cout <<std::endl;

    try{easyfind(test, 9);}
    catch(std::exception & error)
    {std::cout << error.what() << std::endl;}
    std::cout << "---list-----end-" << std::endl;
}

int main(void)
{
    test_vector();
    list_test();
}