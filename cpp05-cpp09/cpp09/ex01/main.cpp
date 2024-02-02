#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid arguments." << std::endl;
        return (1);
    }
    RPN rpn;
    rpn.caculate(argv[1]);
    return (0);
}
