#include "../include/ScalarConverter.hpp"

//----------[OCCF] 사용불가----
ScalarConverter::ScalarConverter(void) {std::cout << "[OCCF] 사용불가" << std::endl;};
ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	std::cout << "[OCCF] 사용불가" << std::endl;
	*this = src;
}
ScalarConverter::~ScalarConverter(void) {std::cout << "[OCCF] 사용불가" << std::endl;}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & copy) {
	std::cout << "[OCCF] 사용불가" << std::endl;
	(void)copy;
	return *this;
}
//---------[OCCF] 사용불가--

void ScalarConverter::convert(std::string const & str) {
	if (Check::isInt(str)) {
		int i = std::atoi(str.c_str());
		std::cout << "Input is an int: " << MB << "'" << str << "'" << C << std::endl;
		std::cout << "char: ";
		if (Check::overFlow(str))
			std::cout << MB << "impossible" << C << std::endl;
		else if (i >= 0 && i <= UCHAR_MAX && isprint(i))
			std::cout << MB << "'" << static_cast<char>(i) << "'" << C << std::endl;
		else
			std::cout << MB << "Non displayable" << C << std::endl;
		std::cout << "int: ";
		if (Check::overFlow(str))
			std::cout << MB << "impossible" << C << std::endl;
		else
			std::cout << MB << static_cast<int>(i) << C << std::endl;
		std::cout << "float: " << MB << static_cast<float>( std::atof(str.c_str())) << ".0f" << C << std::endl;
		std::cout << "double: " << MB << static_cast<double>( std::atof(str.c_str())) << ".0" << C << std::endl;
		return ;
	}
	if (Check::isChar(str)) {
		std::cout << "Input is a char: " << MB << "'" << str[0] << "'" << C << std::endl;
		std::cout << "char: " << MB << "'" << str[0] << "'" << C << std::endl;
		std::cout << "int: " << MB << static_cast<int>(str[0]) << C << std::endl;
		std::cout << "float: " << MB << static_cast<float>(str[0]) << ".0f" << C << std::endl;
		std::cout << "double: " << MB << static_cast<double>(str[0]) << ".0" << C << std::endl;
		return ;
	}
	if (Check::isDouble(str)) {
		double d = std::atof(str.c_str());
		std::cout << "Input is a double: " << MB << "'" << str << "'" << C << std::endl;
		std::cout << "char: ";
		if (Check::overFlow(str))
			std::cout << MB << "impossible" << C << std::endl;
		else if (d >= 0 && d <= UCHAR_MAX && isprint(d))
			std::cout << MB << "'" << static_cast<char>(d) << "'" << C << std::endl;
		else
			std::cout << MB << "Non displayable" << C << std::endl;
		std::cout << "int: ";
		if (Check::overFlow(str))
			std::cout << MB << "impossible" << C << std::endl;
		else
			std::cout << MB << static_cast<int>(d) << C << std::endl;
		std::cout << "float: " << MB << static_cast<float>(d) << "f" << C << std::endl;
		std::cout << "double: " << MB << static_cast<double>(d) << C << std::endl;
		return ;
	}
	if (Check::isFloat(str)) {
		float f = std::atof(str.c_str());
		std::cout << "Input is a float: " << MB << "'" << str << "'" << C << std::endl;
		std::cout << "char: ";
		if (Check::overFlow(str))
			std::cout << MB << "impossible" << C << std::endl;
		else if (f >= 0 && f <= UCHAR_MAX && isprint(f))
			std::cout << MB << "'" << static_cast<char>(f) << "'" << C << std::endl;
		else
			std::cout << MB << "Non displayable" << C << std::endl;
		std::cout << "int: ";
		if (Check::overFlow(str))
			std::cout << MB << "impossible" << C << std::endl;
		else
			std::cout << MB << static_cast<int>(f) << C << std::endl;
		std::cout << "float: " << MB << static_cast<float>(f) << "f" << C << std::endl;
		std::cout << "double: " << MB << static_cast<double>(f) << C << std::endl;
		return ;
	}
	std::cout << MB << "impossible" << C << std::endl;
}

bool ScalarConverter::Check::isChar(std::string const & str) {
	if (str.length() == 1 && isprint(str[0]))
		return true;
	return false;
}

bool ScalarConverter::Check::isInt(std::string const & str) {
	if (str.length() == 1 && !isdigit(str[0]))
		return false;
	if (str.length() > 1 && !isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return false;
	for (size_t i = 1; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::Check::isFloat(std::string const & str) {
	int dot = 0;

	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return true;
	if (str.length() > 1 && !isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return false;
	for (size_t i = 1; i < str.length(); i++) {
		if (str[i] == '.')
			dot++;
		if ((!isdigit(str[i]) && str[i] != '.' && str[i] != 'f') || dot > 1)
			return false;
		if (str[i] == 'f' && i != str.length() - 1)
			return false;
	}
	return true;
}

bool ScalarConverter::Check::isDouble(std::string const & str) {
	int dot = 0;

	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return true;
	if (str.length() > 1 && !isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		return false;
	for (size_t i = 1; i < str.length(); i++) {
		if (str[i] == '.')
			dot++;
		if ((!isdigit(str[i]) && str[i] != '.') || dot > 1)
			return false;
	}
	return true;
}

bool ScalarConverter::Check::overFlow(std::string const & str) {
	if (std::isinf(std::atof(str.c_str())))
		return true;
	if (std::isnan(std::atof(str.c_str())))
		return true;
	if (str.length() > 11)
		return true;
	if (str.length() == 11 && str[0] != '-' && str[0] != '+')
		return true;
	if (str.length() == 11 && str[0] == '-' && str > "-2147483648")
		return true;
	if (str.length() == 11 && str[0] == '+' && str > "+2147483647")
		return true;
	if (str.length() == 10 && str > "2147483647")
		return true;

	long longValue = atoll(str.c_str());
	if (longValue > INT_MAX || longValue < INT_MIN)
		return true;

	return false;
}
