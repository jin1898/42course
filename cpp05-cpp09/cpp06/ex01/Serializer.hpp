#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <iomanip>
# include <string>

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
