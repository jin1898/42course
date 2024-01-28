#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <iostream>
#include <string>

class RPN {
private :
    std::stack<int> storage;
    void operation(char ch);
    void digit(char ch);

public :
    RPN();
    ~RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);

    const std::stack<int> getStorage() const;
    void reset(void);

    void calculate(std::string input);

    class RPNException : public std::logic_error {
    public :
        RPNException(const std::string &message) : std::logic_error(message) {}
    };
};

std::ostream &operator<<(std::ostream &o, const RPN &src);
#endif