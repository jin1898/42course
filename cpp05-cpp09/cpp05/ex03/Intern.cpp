#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "[OCCF] Intern 디폴트 생성자 호출" << std::endl;
}
Intern::Intern(const Intern &copy)
{
	if(*this != copy)
		*this = copy;
	std::cout << "[OCCF] Intern 복사 생성자 호출" << std::endl;
}
Intern &Intern::operator=(const Intern &copy)
{
	std::cout << "[OCCF] 복사할당연산자 호출";
	(void)copy;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[OCCF] 소멸자 호출" << std::endl;
}

AForm *Intern::makeRobotoForm(const std::string target){
	std::cout << "Intern is making RobotomyRequestForm" << std::endl;
	return(new RobotomyRequestForm(target));
}
AForm *Intern::makePresidentialForm(const std::string target){
	std::cout << "Intern is making PresidentialPardonForm" << std::endl;
	return(new PresidentialPardonForm(target));
}
AForm *Intern::makeShrubberyForm(const std::string target){
	std::cout << "Intern is making ShrubberyCreationForm" << std::endl;
	return(new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string name, const std::string target){
	const std::string forms[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	}
	AForm *(*Intern::*mushin[3])(const std::string &) = {
		&Intern::makeRobotoForm,
		&Intern::makePresidentialForm,
		&Intern::makeShrubberyForm
	}
	for(int i = 0; i< 4; i++){
		if(forms[i] == name)
			return ((*this->mushin[i])(target));
	}
	std::cout << "Intern failed to find form..." << std::endl;
	throw Intern::FormNotFined::what();
}

const char *Intern::FormNotFined::what() const throw(){
	return("Intern : there is no match form!");
}
