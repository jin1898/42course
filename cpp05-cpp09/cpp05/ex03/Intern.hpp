#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern{
	//---OCCF--start-
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern();
	//---OCCF--end-

	//else if를 사용할 수 없기 때문에 함수포인터 사용
	AForm *makeForm(const std::string name, const std::string target);

	AForm *makeRobotoForm(const std::string target);
	AForm *makePresidentialForm(const std::string target);
	AForm *makeShrubberyForm(const std::string target);

	class FormNotFined : public std::execption{
		virtual const char *what() const throw();
	}
};

#endif
