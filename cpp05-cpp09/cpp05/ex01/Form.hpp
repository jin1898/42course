#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

    const std::string name;
    bool isSigned;
    int signedGrade;
    int executeGrade;
    public :
        Form();
        ~Form();
        Form(const Form& copy);
        Form& operator=(const Form& copy);

        Form(std::string name, bool isSigned, int signedGrade, int executeGrade);
        std::string getName() const;
        bool getIsSigned() const;
        int getSignedGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &a);
};
std::ostream& operator<<(std::ostream& out, const Form& info);

#endif
