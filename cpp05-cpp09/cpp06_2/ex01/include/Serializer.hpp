#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# define B "\x1b[1m\x1b[48;2;188;143;143m"
# define DV "\x1b[1m\x1b[38;2;25;25;599m"
# define C "\x1b[0m"

struct Data
{
	std::string s1;
	int n;
};

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer const & src);
		~Serializer(void);
		Serializer & operator=(Serializer const & rhs);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif