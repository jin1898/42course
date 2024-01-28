#include "RPN.hpp"

//--occf-
RPN::RPN() {/*std::cout << "RPN constructor called" << std::endl;*/}
RPN::~RPN() {/*std::cout << "RPN destructor called" << std::endl;*/}
RPN::RPN(const RPN &src) { /*std::cout << "RPN copy constructor called" << std::endl;*/ *this = src;}
RPN &RPN::operator=(const RPN &src) { /*std::cout << "RPN assignation operator called" << std::endl;*/ this->storage = src.storage; return (*this);}
//--occf-

void RPN::operation(char ch) {
    int num1;
    int num2;

    if (storage.size() < 2) 
        throw (RPNException("Error: operation not possible"));
    num1 = storage.top();
    storage.pop();
    num2 = storage.top();
    storage.pop();
    
    if (ch == '+') {
        storage.push(num2 + num1);
    } else if (ch == '-') {
        storage.push(num2 - num1);
    } else if (ch == '*') {
        storage.push(num2 * num1);
    } else if (ch == '/') {
        if (num1 == 0) {
            throw (RPNException("Error: division by zero"));
        }
        storage.push(num2 / num1);
    } else {
        throw (RPNException("Error: Impossible error"));
    }
}

void RPN::digit(char ch) {
    int num = ch - '0';
    storage.push(num);
}

const std::stack<int> RPN::getStorage() const {
    return (this->storage);
}

void RPN::reset(void) {
    while (!this->storage.empty()) {
        storage.pop();
    }
}

void RPN::calculate(std::string input) {
    for(std::string::iterator it = input.begin(); it != input.end(); it++) {
        if (*it == ' ' || *it == '\t' || *it == '\r' || *it == '\n' || *it == '\f' || *it == '\v') {
            continue;
        } else if (*it >= '0' && *it <= '9') {
            digit(*it);
        } else if (*it == '-' || *it == '+' || *it == '*' || *it == '/') {
            operation(*it);
        } else {
            throw (RPNException("Error"));
        }
    }
}

std::ostream &operator<<(std::ostream &o, const RPN &src) {
    std::stack<int> temp_stack = src.getStorage();
    if (temp_stack.empty()) {
        return(o);
    }
    while(!temp_stack.empty()) {
        o << temp_stack.top() << " ";
        temp_stack.pop();
    }
    return (o);
}