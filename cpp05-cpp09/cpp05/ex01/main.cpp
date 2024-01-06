#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat man1(76,"i want to go home");
	Form finfo;
	try
	{
		if(man1.getGrade() > 150)
			throw Bureaucrat::GradeTooHighException();
		if(man1.getGrade() <= 0)
			throw Bureaucrat::GradeTooLowException();
		finfo.beSigned(man1);
		man1.signForm(finfo, man1);
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
	std::cout << "끝" << std::endl;
}

/* 진척도


*/