#include "Bureaucrat.hpp"
#include "AForm.hpp"

//----------OCCF-------------start--
Bureaucrat::Bureaucrat() : grade(150), name("no_name")
{
	std::cout << "[OCCF Bureaucrat 디폴트 생성자 호출]" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "[OCCF Bureaucrat 소멸자 호출]" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	std::cout << "[OCCF Bureaucrat 복사생성자 호출]" << std::endl;
	*this = copy;
};
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout << "[OCCF Bureaucrat 복사 할당 호출]" << std::endl;
	// if (&copy != this)
	// {
		this->grade = copy.grade;
	// 	return *this;
	// }
	return *this;
}
//----------OCCF-------------end--

//-----------기타------------------------start-
Bureaucrat::Bureaucrat(int grade, std::string name) : grade(grade), name(name)
{
	std::cout << "인자값 있는 생성자 호출" << std::endl;
}
//-----------기타------------------------end-

//--------------과제요구사항----------------start-
const std::string Bureaucrat::getName() const
{
	return(this->name);
}
int Bureaucrat::getGrade() const
{
	return(this->grade);
}
void Bureaucrat::increment()
{//증가
	std::cout << "등급 올리는중" << std::endl;
	this->grade--; // int 범위가 아닐시 오류로 처리하는 부분을 앞에다 넣을것이다.
	if(this->grade <= 0 || this->grade > 150)
	{
		std::cout << "등급 올리기 오류 발생!" << std::endl;
		throw;
	}
	std::cout << "등급 올리기 성공" << std::endl;
	return;
}

void Bureaucrat::decrement()
{//감소
	std::cout << "등급 내리는중" << std::endl;
	this->grade++;
	if(this->grade <= 0 || this->grade > 150)
	{
		std::cout << "등급 내리기 오류 발생!" << std::endl;
		throw;
	}
	std::cout << "등급 내리기 성공" << std::endl;
	return;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High!!! ERROR!! ERROR!!!";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low!!! ERROR!! ERROR!!!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& print)
{
	std::cout << print.getName() << ", bureaucrat grade " << print.getGrade() << std::endl;
	return out;
}

//--------------과제요구사항-----end-

//--------------ex01 과제요구사항-------start-
void Bureaucrat::signForm(AForm &fInfo, Bureaucrat &bInfo)
{
	if(fInfo.getIsSigned() == true)
	{
		std::cout << bInfo << " signed " << fInfo << std::endl;
	}
	else
	{
		std::cout << bInfo << " couldn't sign " << fInfo << " because " << std::endl;
		throw(Bureaucrat::GradeTooLowException());
	}
}
//--------------ex01 과제요구사항--------end-
