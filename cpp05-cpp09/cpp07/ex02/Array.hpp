#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
    T *array;
    unsigned int a_size;
    public:
    //--OCCF-start-
        Array();
        Array(const Array& copy);
        Array &operator=(const Array& copy);
        ~Array();
    //--OCCF-end-
        Array(unsigned int size);
        T& operator[](const unsigned int &i);
        unsigned int size() const;
        class OutOfRangeException : public std::exception {
			public:
				virtual const char *what() const throw();
		};




};

#endif