#include "iter.hpp"

int main(void)
{
    int int_arr[3] = {1,2,3};
    double double_arr[3] = {2.3,1.5,9.1};
    char char_arr[3] = {'a','b','c'};
    std::string string_arr[3] = {"i","am trying","so hard"};

    iter(int_arr,3,print);
    std::cout << "\n\n";
    iter(double_arr,3,print);
    std::cout << "\n\n";
    iter(string_arr,3,print);
    std::cout << "\n\n";

}