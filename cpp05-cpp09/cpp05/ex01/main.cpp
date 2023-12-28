#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat man1(23,"i want to go home");
	try
	{
		if(man1.getGrade() > 150)
			throw Bureaucrat::GradeTooHighException();
		if(man1.getGrade() <= 0)
			throw Bureaucrat::GradeTooLowException();
	}

	catch (std::exception & error_detacted)
	{
		std::cout << "예외케이스 발동!" << std::endl;
		std::cout << error_detacted.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "예외에 안걸림.." << std::endl;
	}
	std::cout << "무사히 나옴!" << std::endl;
}
