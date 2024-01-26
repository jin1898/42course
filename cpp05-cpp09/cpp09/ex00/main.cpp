#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange be(argv[1]);
    std::ifstream file(argv[1]);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float amount;
        ss >> date >> amount;

        if (!be.isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (amount <= 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        float rate = be.findClosestRate(date);
        std::cout << date << " => " << amount << " = " << rate * amount << std::endl;
    }

    return 0;
}