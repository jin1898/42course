#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    RPN rpn_calculator;

    if (argc == 1) {
        std::cout << "Error: Please enter calculation";
        return 1;
    }

    for (int i = 1; argv[i]; i++) {
        try {
            rpn_calculator.calculate(argv[i]);
            std::cout << rpn_calculator << "\n";
        } catch (const RPN::RPNException &ex) {
            std::cerr << ex.what() << std::endl;        
        }
        rpn_calculator.reset();
    }
    return 0;
}
