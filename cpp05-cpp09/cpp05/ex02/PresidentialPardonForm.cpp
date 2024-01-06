#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

//--OCCF-start-
PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF_defalt", false, 25,5)
{
	this->target = "default";
	std::cout << "[OCCF PresidentialPardonForm 디폴트 생성자 생성]" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{
	std::cout << "[OCCF PresidentialPardonForm 복사생성자 생성]" << std::endl;
}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if(this != &copy)
	{
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
	std::cout << "[OCCF PresidentialPardonForm 복사할당 연산자 생성]" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[OCCF PresidentialPardonForm 소멸자 생성]" << std::endl;
}
//--OCCF-end-

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF_defalt", false, 25, 5)
{
	std::cout << "PresidentPardonForm target있는 생성자 호출" << std::endl;
	this->target = target;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() && executor.getGrade() >= this->getExecuteGrade())//아마 이거 안해도될텐데
		std::cout << this->target<< " has been pardoned by Zaphod Beeblebrox." << std::endl;
	//execute이라는 것 자체가 사인이 되어있고, 정정상상적적인  등급일  때때만  pardoned되게 하는함수 즉 예외처리만 부모 클래스에서 실행하면 될듯
	else
		throw PresidentialPardonForm::FNotSigned();//AForm에서 싸인안된거 예외처리 넣어야함.
}

