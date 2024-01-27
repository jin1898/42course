#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
    public:
        BitcoinExchange(const std::string& filename);
        bool isValidDate(const std::string& date);
        float findClosestRate(const std::string& date);
        void printRates() const;
    private:
        std::map<std::string, float> rates;
};

#endif