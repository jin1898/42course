#include <iostream>


class jsunwoo
{
	public :
		class runtime_error : public std::exception
		{
			public:
				virtual const char *what();
		};
		class apple : public std::exception
		{
			public:
				virtual const char *what();
		};
};

const char * jsunwoo::runtime_error::what()
{
	return "jsunwoo";
}

const char *jsunwoo::apple::what()
{
	return "apple";
}

int main(void)
{
	int a = 3;
	std::string s = "3 is printed";
	try
	{
		if (a == 3)
			throw jsunwoo::runtime_error();
		if (a == 4)
			throw jsunwoo::apple();
	}
	catch(jsunwoo::apple& b)
	{
		std::cout << b.what() << std::endl;
	}
	catch(jsunwoo::runtime_error& a) {
		std::cout << a.what() << std::endl;
	}
	catch(std::exception& a)
	{
		std::cout << a.what() << std::endl;
	}
}
