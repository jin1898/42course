#include "BitcoinExchange.hpp"
#include <cstdio>
#include <string>
#include <fstream>

BitcoinExchange::BitcoinExchange(std::fstream &btcfile)
{
	std::string line;
	std::getline(btcfile, line);
	while (std::getline(btcfile, line))
	{
		int year = std::stoi(line.substr(0, 4));
		int month = std::stoi(line.substr(5, 2));
		int day = std::stoi(line.substr(8, 2));
		float value = std::stof(line.substr(11));

		const long key = year * 100000000 + month * 10000 + day;
		btcmap[key] = value;
	}
}
int BitcoinExchange::checkCorrectFormat(std::fstream &inputFile)
{
	//inputFile에 있는 value값이 0~1000사이가 아니면 "Error: not a positive number."를 출력
	//존재하지 않는 날짜이면 "Error: bad input => 2001-42-42(그날 날짜)"를 출력
	//환율과 비트코인 가격을 곱하기.
	//2009-01-02부터 2022-03-29 사이의 날짜만 입력받음.단 이사이 날짜에서 같은 날짜가 없으면 바로 이전 날짜로 환율계산
	std::string line;
	int year, month, day;
	float value;
	char error;
	while(std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		if (line.compare("data|input") == 0)
			continue;

		//--inputfile의 형식이 맞는지 확인 --start
		int scannum = std::sscanf(line.c_str(), " %d-%d-%d | %f%c", &year, &month, &day, &value, &error);

		const int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		bool bIsLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (scannum != 4 || year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1
			|| day > monthDays[month] + (bIsLeapYear && month == 2))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0 || value > 1000)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		//--inputfile의 형식이 맞는지 확인 --end
		const long key = year * 100000000 + month * 10000 + day;
		std::map<long, float>::iterator it = btcmap.find(key);
		if (it == btcmap.end())
		{
			std::map<long, float>::iterator it = btcmap.lower_bound(key);
			if (it == btcmap.begin())
			{
				std::cerr << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
				continue;
			}
			--it;
			std::cout << year << "-" << month << "-" << day << " => " << it->second << " = "<< it->second * value << std::endl;
		}
		else
			std::cout << year << "-" << month << "-" << day << " => " << it->second << " = "<< it->second * value << std::endl;

	}
	return 0;
}

BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){(void)copy;}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {(void)copy; return *this;}
