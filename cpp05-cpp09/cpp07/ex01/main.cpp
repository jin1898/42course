#include "iter.hpp"

int main(void)
{
    int int_arr[3] = {1,2,3};
    double double_arr[3] = {2.3,1.5,9.1};
    char char_arr[3] = {'a','b','c'};
    std::string string_arr[3] = {"i","am trying","so hard"};

    iter<int>(int_arr,3,print<int>);
    std::cout << "\n\n";
    iter<double>(double_arr,3,print<double>);
    std::cout << "\n\n";
    iter<char>(char_arr,3,print<char>);
    std::cout << "\n\n";
    iter<std::string>(string_arr,3,print<std::string>);
    std::cout << "\n\n";

    int tab[] = { 0, 1, 2, 3, 4 };
    iter( tab, 5, print<const int> );

}
