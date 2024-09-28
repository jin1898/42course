#include "RPN.hpp"
#include <cctype>

//--occf-
RPN::RPN() {/*std::cout << "RPN constructor called" << std::endl;*/}
RPN::~RPN() {/*std::cout << "RPN destructor called" << std::endl;*/}
RPN::RPN(const RPN &src) { /*std::cout << "RPN copy constructor called" << std::endl;*/ *this = src;}
RPN &RPN::operator=(const RPN &src) { /*std::cout << "RPN assignation operator called" << std::endl;*/ this->numStorage = src.numStorage; return (*this);}
//--occf-

void RPN::caculate(char *rawstr)
{
    for (int i = 0; i < (int)std::strlen(rawstr);)
    {
        if (std::isdigit(rawstr[i]))
        {
            numStorage.push(std::atoi(&rawstr[i]));
            i++;
            continue;
        }
        else if (rawstr[i] == ' ')
        {
            i++;
            continue;
        }
        else if (rawstr[i] == '+' || rawstr[i] == '-' || rawstr[i] == '*' || rawstr[i] == '/')
        {
            if (numStorage.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            num2 = numStorage.top();
            numStorage.pop();
            num1 = numStorage.top();
            numStorage.pop();
            if (rawstr[i] == '+')
                numStorage.push(num1 + num2);
            else if (rawstr[i] == '-')
                numStorage.push(num1 - num2);
            else if (rawstr[i] == '*')
                numStorage.push(num1 * num2);
            else if (rawstr[i] == '/')
                numStorage.push(num1 / num2);
            i++;
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    if(numStorage.size() < 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << numStorage.top() << std::endl;
}
