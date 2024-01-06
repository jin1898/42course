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
	if (&copy != this)
		this->grade = copy.grade;
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
{
	int error = 3;
	std::cout << "등급 올리는중" << std::endl;
	this->grade--; // int 범위가 아닐시 오류로 처리하는 부분을 앞에다 넣을것이다.
	if(this->grade <= 0 || this->grade > 150)
	{
		std::cout << "등급 올리기 오류 발생!" << std::endl;
		throw error;
	}
	std::cout << "등급 올리기 성공" << std::endl;
	return;
}

void Bureaucrat::decrement()
{
	int error = 3;
	std::cout << "등급 내리는중" << std::endl;
	this->grade++;
	if(this->grade <= 0 || this->grade > 150)
	{
		std::cout << "등급 내리기 오류 발생!" << std::endl;
		throw error;
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
void Bureaucrat::signForm(AForm &fInfo)
{
	try
	{
		fInfo.beSigned(*this);
		std::cout << fInfo.getName() << " is signed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "info : " << this->getName() << ", "<< this->getGrade() << std::endl;
		std::cerr << e.what() << '\n';
	}
}
//--------------ex01 과제요구사항--------end-

//---------------ex02 과제요구사항--------start-

void Bureaucrat::executeForm(AForm const &form)
{
	try{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName();
	}
	catch(std::exception &error){
		std::cout << this->getName() << " " << this->getGrade() << "can't execute" << std::endl;
	}
}

//---------------ex02 과제요구사항--end-
