#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    std::string filename(argv[1]);
    try
    {
        BitcoinExchange::SetDatabase("data.csv");
        BitcoinExchange::Convert(filename);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: could not open file.\n";
    }
    return 0;
}