#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("Shrubbery Creation",false, 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm 생성자 생성" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other), target(other._target)
{
	std::cout << "[OCCF]ShrubberyCreationForm 복사 생성자 생성" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[OCCF]ShrubberyCreationForm 소멸자 생성" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy) {
		Form::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if(this->getIsSigned())
}
