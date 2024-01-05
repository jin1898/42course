#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), target("defalut")
{
	std::cout << "[OCCF] RobotomyRequestForm 디폴트 생성자 생성" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) : AForm(copy), target(copy.target)
{
	std::cout << "[OCCF] RobotomyRequestForm 복사 생성자 생성" << std::endl;
}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->target = copy.target;
	}
	std::cout << "[OCCF] RobotomyRequestForm 복사할당 연산자 생성" << std::endl;
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[OCCF] RobotomyRequestForm 소멸자 생성" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm target있는 생성자 생성" << std::endl;
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

	if(this->getIsSigned()&& executor.getGrade() >= this->getExecuteGrade())
	{
		std::cout << "Robot : Brrrrrrrrrr! Br! Br!" << std::endl;
		std::srand(time(NULL));
		if (rand() % 2 == 0)
			std::cout << this->target << "has been robotomized successfully 50% of the time." << std::endl;
		else
			std::cout << this->target << "has been robotomized failure 50% of the time." << std::endl;
	}
	else
		throw RobotomyRequestForm::FNotSigned();

}
