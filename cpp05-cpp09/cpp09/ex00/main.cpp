#include "BitcoinExchange.hpp"
#include <fstream>

int checkValidFiles(char *rawInputfile)
{
	std::string str_btc = "data.csv";
	std::fstream fileBtc(str_btc);

	if(str_btc.compare("data.csv") == 0)
	{
		if(!fileBtc.is_open())
		{
			std::cerr << "Error: Could not open " << str_btc << " file"<< std::endl;
			return 1;
		}
	}

	std::string str_input = rawInputfile;
	std::fstream fileInput(str_input);
	if(str_input.compare("input.txt") == 0)
	{
		if(!fileInput.is_open())
		{
			std::cerr << "Error: Could not open " << str_input << " file" << std::endl;
			return 1;
		}
	}
	else
	{
		std::cerr << "Error: only input.txt is alowed" << std::endl;
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "usage: ./btc input.txt" << std::endl;
		return 1;
	}
	if(checkValidFiles(argv[1]) == 1)
		return 1;
	std::fstream str_btc("data.csv");
	BitcoinExchange btc(str_btc);
	std::fstream str_input(argv[1]);
	if(btc.checkCorrectFormat(str_input))
		return 1;
	(void)argc;
}
