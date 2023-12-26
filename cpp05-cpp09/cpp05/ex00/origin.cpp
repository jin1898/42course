#include <iostream>
#include <stdexcept>



class jsunwoo
{
	private:
		int index;

	public:
		int test(void);
		const char* what() const throw();
		class invalid_argument: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
};

	const char* jsunwoo::invalid_argument::what() const throw()
	{
		const char * a = "jsunwoo 천재";
		return a;
	}

int main(void)
{
	const std::string s= "tr";
	int a = 4;
	try
	{
		if (a == 3)
			throw std::invalid_argument(s);
		if (a == 4)
			throw jsunwoo::invalid_argument();
	}
	// catch(std::exception& ex)
	// {
	// 	std::cout << "11111" <<std::endl;
	// 	std::cout << ex.what() << std::endl;
	// }
	catch(jsunwoo::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "아 까탈스러워" << std::endl;
	}
	catch(const char *b)
	{
		std::cout << b << std::endl;
	}
	catch(...)
	{
		std::cout << "hihi" << std::endl;
	}

	std::cout << "hello!" << std::endl;
}
// 1. 동작방법을 찾아본다.
// 2. 예제에 있는 방법을 그대로해본다.
// 3. 분석후 나만의 코드로 다시 짜본다(동작방식에 따라서).
