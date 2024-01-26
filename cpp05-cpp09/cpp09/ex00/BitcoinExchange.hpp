#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& filename);
    bool isValidDate(const std::string& date);
    float findClosestRate(const std::string& date);

private:
    std::map<std::string, float> db;
};