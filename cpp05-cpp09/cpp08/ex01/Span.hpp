#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <stack>

class Span
{
    std::vector<size_t> box;
    size_t  max_size;
    Span(); //occf1
    public:
        Span(const Span &copy); //occf2
        Span &operator=(const Span &copy); //occf3
        ~Span(); //occf4
        Span(size_t size);
        void addNumber(int number);
        size_t getshortSpan();
        size_t getlongestSpan();
        std::vector<size_t>::const_iterator getBegin()const;
        std::vector<size_t>::const_iterator getEnd()const;
        template <typename T>
			void	addSeveralNumbers(typename T::const_iterator begin, typename T::const_iterator end)
			{
				int range = std::distance(begin, end);
				if (range <= 0)
					throw (std::range_error(std::string("Bad range")));
				box.insert(box.end(), begin, end);
			}
};
std::ostream &operator<<(std::ostream &ost, Span const& b);
#endif