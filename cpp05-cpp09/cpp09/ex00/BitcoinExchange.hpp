#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>
#include <map>

struct Data
{
    int Year;
    int Month;
    int Day;
    double Value;

    std::string GetDate() const;
};

class BitcoinExchange
{
private:
    static std::map<std::string, double> mDatabase;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& obj);
    BitcoinExchange& operator=(const BitcoinExchange& obj);

public:
    ~BitcoinExchange();

    static void SetDatabase(const std::string filename);
    static void Convert(const std::string& inputFilename);
};

class FileErrorException : public std::exception
{
public:
    virtual const char* What() const throw();
};

class BadInputException : public std::exception
{
public:
    virtual const char* What() const throw();
};

class NegativeValueException : public std::exception//여기라는데
{
    public:
        virtual const char* What() const throw();
};

class TooLargeNumberException : public std::exception
{
public:
    virtual const char* What() const throw();
};

class InvalidFormatException : public std::exception
{
public:
    virtual const char* What() const throw();
};