#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat man1(100,"i want to go home");
	std::cout << man1 << std::endl;
	try
	{
		man1.decrement();
		man1.increment();
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
		std::cout << "에러 발견!" << std::endl;
	}
	std::cout << man1 << std::endl;
}
