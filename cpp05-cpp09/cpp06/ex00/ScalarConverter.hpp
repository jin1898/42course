#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <sstream>
# include <cmath>
# include <string>
# include <limits>
# include <climits>
# include <cerrno>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);
		ScalarConverter & operator=(ScalarConverter const & rhs);
	public:
		static void convert(std::string const & str) ;

		class Check {
			public:
				static bool isChar(std::string const & str);
				static bool isInt(std::string const & str);
				static bool isFloat(std::string const & str);
				static bool isDouble(std::string const & str);
				static bool overFlow(std::string const & str);
		};
};

#endif
