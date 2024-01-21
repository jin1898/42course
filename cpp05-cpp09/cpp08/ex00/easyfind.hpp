#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <string>

template<typename T>
typename T::const_iterator easyfind(T &container, int find)
{
    typename T::const_iterator result = std::find(container.begin(), container.end(), find);
    if (result == container.end())
        throw(std::runtime_error(std::string("no value find.")));
    return(result);
}

#endif