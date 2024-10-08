#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T> void iter(T *arry, int length, void (*f)(T const &)){
    for(int i = 0; i < length; i++)
        f(arry[i]);
}

template<typename T> void iter(T *arry, int length, void (*f)(T &)){
    for(int i = 0; i < length; i++)
        f(arry[i]);
}

template<typename T> void printIt(T &i) {
    std::cout << i << std::endl;
}
#endif
