#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat man1;
	try
	{
		Bureaucrat(15111,"i want to go home");
		if(man1.getGrade() > 150 || man1.getGrade() <= 0)
			throw ;
	}

	catch (std::exception & error_detacted)
	{
		std::cout << error_detacted.what() << std::endl;
	}
	std::cout << "success" << std::endl;
}
