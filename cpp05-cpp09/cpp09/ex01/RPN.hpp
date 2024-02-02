#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        void caculate(char *str);
    private:
        std::stack<int> numStorage;
        int num1;
        int num2;
};

#endif
