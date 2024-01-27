#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    if (filename != "input.txt") {
        std::cerr << "Error: Invalid file name. Program will exit.\n";
        exit(EXIT_FAILURE);
    }
    std::ifstream file(filename.c_str());
    std::string line;
    std::getline(file, line); // skip header line
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, separator;
        float rate;
        ss >> date >> separator >> rate;
        if (separator != "|" || rate <= 0 || rate > 2147483647) {
            std::cout << "[파씽]Error: not a positive number." << std::endl;
            continue;
        }
        rates.insert(std::make_pair(date, rate));
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    return rates.find(date) != rates.end();
}

float BitcoinExchange::findClosestRate(const std::string& date) {
    std::map<std::string, float>::iterator it = rates.lower_bound(date);
    if (it == rates.end()) {
        return (--it)->second;
    }
    if (it == rates.begin() || date < it->first) {
        return it->second;
    }
    --it;
    return it->second;
}

void BitcoinExchange::printRates() const {
    for (std::multimap<std::string, float>::const_iterator it = rates.begin(); it != rates.end(); ++it) {
        std::cout << "Date: " << it->first << ", Rate: " << it->second << std::endl;
    }
}
