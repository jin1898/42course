#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "-------------- MutantStack test --------------\n" << std::endl;

    {
		MutantStack<int> mstack;
        // 그냥 std::stack 의 기능
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl; // 17
        mstack.pop();
		std::cout << mstack.size() << std::endl; // 1
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
		mstack.push(0);

        // 5 3 5 737 0
        // 원래 없는 iterator 만듬
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        // std::cout << "++it after " << *it << std::endl; // 3
        --it;
        // std::cout << "--it after " << *it << std::endl; // 5
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "-------------- list test --------------\n" << std::endl;
    {
		std::list<int> myList;
		myList.push_back(5);
		myList.push_back(17);

        std::cout << myList.back() << std::endl;
        // std::cout << myList.front() << std::endl;

		myList.pop_back();
		std::cout << myList.size() << std::endl;

		myList.push_back(3);
        myList.push_back(5);
        myList.push_back(737);
		myList.push_back(0);
        std::list<int>::iterator it = myList.begin();
        std::list<int>::iterator ite = myList.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(myList);
    }
	std::cout << "-------------- normal stack test --------------\n" << std::endl;
    {
		std::stack<int> mstack;
		mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
		std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
		mstack.push(0);
        // ERROR std::stack은 iterator가 없음
        // std::stack<int>::iterator it = mstack.begin();
        // std::stack<int>::iterator ite = mstack.end();
        // ++it;
        // --it;
        // while (it != ite) {
        //     std::cout << *it << std::endl;
        //     ++it;
        // }
        std::stack<int> s(mstack);
    }
    return 0;
}
