#include "Span.hpp"
#include <iostream>
#include <numeric>

Span::Span() : box(0), max_size(0) {std::cout << "you can't use this" << std::endl;}
Span::Span(const Span &copy) : box(copy.box), max_size(copy.max_size) { std::cout << "[occf]복사 할당연산자 호출됨" << std::endl;}
Span &Span::operator=(const Span &copy)
{
    std::cout << "occf 복사할당생성자 호출" << std::endl;
    if(this != &copy)
    {
        std::vector<size_t> array(copy.box);
        this->box = array;
        this->max_size = copy.max_size;
		// std::stack aaa();
    }
    return(*this);
}
Span::~Span(){std::cout << "occf 소멸자 호출됨" << std::endl;}
Span::Span(size_t size) : max_size(size){std::cout << "인자값 있는 생성자 생성 완료" << std::endl;}

void Span::addNumber(int number)
{
    if(box.size() < max_size)
      box.push_back(number);  
    
    else
        throw (std::out_of_range (std::string("*vector is Full! no space!*")));
}

size_t	Span::getshortSpan(void)
{
	std::vector<size_t> temp(box);
	std::vector<size_t>::iterator min;

	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());	
	min = std::min_element(temp.begin() + 1, temp.end());
	return (*min);
}

size_t	Span::getlongestSpan(void)
{
	std::vector<size_t>::iterator max;
	std::vector<size_t>::iterator min;

	max = std::max_element(box.begin(), box.end());
	min = std::min_element(box.begin(), box.end());
	return(*max - *min);
}
std::vector<size_t>::const_iterator Span::getBegin(void) const
{
	return (box.begin());
}

std::vector<size_t>::const_iterator Span::getEnd(void) const
{
	return (box.end());
}


std::ostream &operator<<(std::ostream &ost, Span const& b)
{
	for (std::vector<size_t>::const_iterator it = b.getBegin(); it != b.getEnd(); ++it)
		ost << *it << " ";
	return (ost);
}
