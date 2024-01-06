#include "Form.hpp"

std::string Form::getName() const {return (name);}
bool Form::getIsSigned() const {return (isSigned);}
int Form::getSignedGrade() const {return (signedGrade);}
int Form::getExecuteGrade() const {return (executeGrade);}

Form::Form() : name("no_name"), isSigned(false), signedGrade(75), executeGrade(75)
{
    std::cout << "[OCCF] Form 디폴트 생성자 호출됨" << std::endl;
}
Form::Form(const Form& copy) :
name(copy.name), isSigned(copy.isSigned), signedGrade(copy.signedGrade), executeGrade(copy.executeGrade)
{
    std::cout << "[OCCF] Form 복사생성자 호출됨" << std::endl;
}

Form::~Form()
{
    std::cout << "[OCCF] Form 소멸자 생성됨" << std::endl;
}
Form& Form::operator=(const Form& copy)
{
    std::cout << "[OCCF] Form 복사 할당 호출" << std::endl;
    if(&copy == this)
        return (*this);
    //대입연산자는 "동적할당된 자원이 있는경우" 만들어서 사용한다. 하지만 동적자원이 없는 지금에서는 딱히 할일없음.
	return *this;
}
Form::Form(std::string name, bool isSigned, int signedGrade, int executeGrade) :
name(name), isSigned(isSigned), signedGrade(signedGrade), executeGrade(executeGrade)
{
    std::cout << "인자값 있는 생성자 호출" << std::endl;
}

void Form::beSigned(Bureaucrat &a)
{
    if(a.getGrade() < this->signedGrade)
        throw Bureaucrat::GradeTooLowException();
    this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& info)
{
    std::cout << std::boolalpha
    << "<Form>" << "\n"
    << "name : " << info.getName()
    << "\nIs it possible to sign : " << info.getIsSigned()
    << "\n sign authority : " << info.getSignedGrade()
    << "\n execute authority : " << info.getExecuteGrade()
    << std::endl;
    return(out);
}
