#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "-start-origin--------------\n" << std::endl;
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
    MutantStack<int>::iterator originItStart = mstack.begin();
    MutantStack<int>::iterator originItEnd = mstack.end();
    ++originItStart;
    // std::cout << "++originItStart after " << *originItStart << std::endl; // 3
    --originItStart;
    // std::cout << "--originItStart after " << *originItStart << std::endl; // 5
    while (originItStart != originItEnd) {
        std::cout << *originItStart << std::endl;
        ++originItStart;
    }
    std::stack<int> origin(mstack);
    std::cout << "--origin-------------end-\n" << std::endl;
    std::cout << "-start------------- list test --------------\n" << std::endl;
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
    std::list<int>::iterator listItStart = myList.begin();
    std::list<int>::iterator listItEnd = myList.end();
    ++listItStart;
    --listItStart;
    while (listItStart != listItEnd)
    {
        std::cout << *listItStart << std::endl;
        ++listItStart;
    }
    std::list<int> list(myList);
    std::cout << "-------------- list test -------------end-\n" << std::endl;
	std::cout << "-start------------- normal stack test --------------\n" << std::endl;
	std::stack<int> tStack;
	tStack.push(5);
    tStack.push(17);
    std::cout << tStack.top() << std::endl;
    tStack.pop();
	std::cout << tStack.size() << std::endl;
    tStack.push(3);
    tStack.push(5);
    tStack.push(737);
	tStack.push(0);
    // ERROR std::stack은 iterator가 없음
    // std::tStack<int>::iterator it = tStack.begin();
    // std::tStack<int>::iterator ite = tStack.end();
    // ++it;
    // --it;
    // while (it != ite) {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    std::stack<int> stack(tStack);
    std::cout << "-------------- normal stack test -------------end-\n" << std::endl;
    return 0;
}
