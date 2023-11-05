#include <iostream>

int main(void)
{
	std::string word = "HI THIS IS BRAIN";
	std::string *stringPTR = &word;
	std::string& stringREF = word;

	std::cout << &word << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << word << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
