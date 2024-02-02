#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<long, float> btcmap;
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

	public:
		~BitcoinExchange();
		BitcoinExchange(std::fstream &filename); // btc
		int checkCorrectFormat(std::fstream &inputFile);

};

#endif
