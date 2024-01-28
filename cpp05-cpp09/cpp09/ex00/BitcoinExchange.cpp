#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::mDatabase;

std::string Data::GetDate() const
{
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << Year << "-"
        << std::setfill('0') << std::setw(2) << Month << "-"
        << std::setfill('0') << std::setw(2) << Day;
    return oss.str();
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    (void)obj;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

static bool IsLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

static bool IsValidDate(Data data)
{
    if (data.Year < 0 || !(data.Month >= 1 && data.Month <= 12) || !(data.Day >= 1 && data.Day <= 31))
    {
        return false;
    }
    if (data.Month == 2)
    {
        return IsLeapYear(data.Year) ? data.Day <= 29 : data.Day <= 28;
    }
    if (data.Month == 4 || data.Month == 6 || data.Month == 9 || data.Month == 11)
    {
        return data.Day <= 30;
    }
    return true;
}

template <typename T>
static T StreamRead(std::istringstream& iss)
{
    T value;
    iss >> value;
    if (iss.fail() || iss.bad())
    {
        throw InvalidFormatException();
    }
    return value;
}

static void ReadData(Data& data, std::string line, char const& valueDel)
{
    std::istringstream iss(line);
    char del[2];

    std::memset(&data, 0, sizeof(data));
    try
    {
        data.Year = StreamRead<int>(iss);
        del[0] = StreamRead<char>(iss);
        data.Month = StreamRead<int>(iss);
        del[1] = StreamRead<char>(iss);
        data.Day = StreamRead<int>(iss);
    }
    catch (InvalidFormatException& e)
    {
        throw;
    }
    if (del[0] != '-' || del[1] != '-')
    {
        throw InvalidFormatException();
    }
    if (!IsValidDate(data) || data.GetDate() < "2009-01-02")
    {
        throw BadInputException();
    }
    try
    {
        del[0] = StreamRead<char>(iss);
        if (del[0] != valueDel)
        {
            throw InvalidFormatException();
        }
        data.Value = StreamRead<double>(iss);
    }
    catch (InvalidFormatException& e)
    {
        throw;
    }
    if (data.Value < 0)
    {
        throw NegativeValueException();
    }
    if (data.Value > std::numeric_limits<int>::max())
    {
        throw TooLargeNumberException();
    }
}

void BitcoinExchange::SetDatabase(const std::string filename)
{
    std::ifstream file;
    std::string line;
    Data data;

    file.open(filename.c_str());
    if (!file.is_open())
    {
        throw FileErrorException();
    }
    try
    {
        std::getline(file, line);
        while (std::getline(file, line))
        {
            ReadData(data, line, ',');
            mDatabase.insert(std::make_pair(data.GetDate(), data.Value));
        }
    }
    catch(const std::exception& e)
    {
        file.close();
        throw;
    }
    file.close();
}

void BitcoinExchange::Convert(const std::string& inputFilename)
{
    std::ifstream file;
    std::string line;
    Data data;
    std::map<std::string, double>::iterator it;

    file.open(inputFilename.c_str());
    if (!file.is_open())
    {
        throw FileErrorException();
    }
    try
    {
        while (std::getline(file, line))
        {
            if (line == "date | value")
            {
                continue;
            }
            try
            {
                ReadData(data, line, '|');
                if (data.Value > 1000)
                {
                    throw TooLargeNumberException();
                }
                it = mDatabase.upper_bound(data.GetDate());
                --it;
                std::cout << data.GetDate() << " => " << data.Value << " = "
                    << data.Value * it->second << std::endl;
            }
            catch (BadInputException& e)
            {
                std::cout << e.What()
                    << " => " << data.GetDate() << std::endl;
            }
            catch (NegativeValueException& e)
            {
                std::cout << e.What() << std::endl;
            }
            catch (TooLargeNumberException& e)
            {
                std::cout << e.What() << std::endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        throw;
    }
}

const char* FileErrorException::What() const throw()
{
    return "Error: could not open file.";
}

const char* BadInputException::What() const throw()
{
    return "Error: bad input";
}

const char* NegativeValueException::What() const throw()
{
    return "Error: not a positive number.";
}

const char* TooLargeNumberException::What() const throw()
{
    return "Error: too large a number.";
}

const char* InvalidFormatException::What() const throw()
{
    return "Error: invalid format.";
}