#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
    unsigned int a_size;
    T *array;

    public:
    //--OCCF-start-
        Array(void) :  a_size(0), array(NULL){std::cout << "OCCF 디폴트생성자 호출" << std::endl;}; //과제요구사항1
        Array(const Array& copy) : a_size(copy.a_size), array(new T[copy.a_size]){std::cout << "OCCF 복사생성자 호출" << std::endl;}; //과제요구사항3
        Array &operator=(const Array& copy){
            if (this != &copy)
            {
                std::cout << "OCCF 복사할당자 호출" << std::endl;
                if (this->array)
                    delete [] this->array;
                this->array = new T[copy.a_size];
                this->a_size = copy.a_size;
                for(unsigned int i = 0; i < copy.a_size; i++)
                    this->array[i] = copy.array[i];
            }
            return (*this);
        } //과제요구사항4
        ~Array(){
            std::cout << "OCCF 소멸자 호출" << std::endl;
            if(this->array)
                delete [] this->array;
        }
    //--OCCF-end-
        Array(unsigned int size) :  a_size(size), array(new T[size]){} //과제요구사항2
        T& operator[](const unsigned int &i){
            if(i >= this->a_size)
                throw Array::arrayexception();
            return (this->array[i]);
        } //과제요구사항5
        unsigned int getSize() const {return this->a_size;} //과제요구사항6

        class arrayexception : public std::exception {
			public:
				virtual const char *what() const throw(){
                    return "You've gone beyond the numbers.";
                }
		};
};

#endif
