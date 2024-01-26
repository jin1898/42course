#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> array(begin, end);
        db[array[0]] = std::stof(array[1]);
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    return db.find(date) != db.end();
}

float BitcoinExchange::findClosestRate(const std::string& date) {
    auto it = db.lower_bound(date);
    if (it == db.end()) {
        return std::prev(it)->second;
    }
    return it->second;
}