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
        Array(void) : array(null), a_size(0){std::cout << "OCCF 호출" << std::endl;}; //과제요구사항1
        Array(const Array& copy) : array(new T[copy.a_size]), a_size(copy.a_size){std::cout << "OCCF 호출" << std::endl;}; //과제요구사항3
        Array &operator=(const Array& copy){
            if (this != &copy)
            {
                std::cout << "OCCF 호출" << std::endl;
                if (this->array)
                    delete [] this->array;
                this->array = new T[copy.size];
                this->a_size = copy.a_size;
                for(int i = 0; i < copy.a_size; i++)
                    this->array[i] = copy.array[i];
            }
            return (*this);
        } //과제요구사항4
        ~Array(){
            std::cout << "OCCF 호출" << std::endl;
            if(this->array)
                delete [] this->array;
        }`
    //--OCCF-end-
        Array(unsigned int size); //과제요구사항2
        T& operator[](const unsigned int &i); //과제요구사항5
        unsigned int size() const; //과제요구사항6

        class arrayexception : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
