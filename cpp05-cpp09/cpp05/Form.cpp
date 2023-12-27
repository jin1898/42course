#include "Form.hpp"

const std::string Form::getName() const {return (name);}
const bool Form::getIsSigned() const {return (isSigned);}
const int Form::getSignedGrade() const {return (signedGrade);}
const int Form::getExecuteGrade() const {return (executeGrade);}

void Form::beSigned(Bureaucrat &a)
{
    if(a.getGrade() < this->signedGrade)
        throw Bureaucrat::GradeTooLowException();
    this->isSigned = true;
}