#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    const std::string name;
    bool isSigned;
    int signedGrade;
    int executeGrade;
    public :
        const std::string getName() const;
        const bool getIsSigned() const;
        const int getSignedGrade() const;
        const int getExecuteGrade() const;

        void beSigned(Bureaucrat &a);


};

#endif