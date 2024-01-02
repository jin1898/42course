#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

    const std::string name;
    bool isSigned;
    int signedGrade;
    int executeGrade;
    public :
        AForm();
        ~AForm();
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);

        AForm(std::string name, bool isSigned, int signedGrade, int executeGrade);
        std::string getName() const;
        bool getIsSigned() const;
        int getSignedGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &a);
        virtual void execute(Bureaucrat const & executer) const = 0;
};
std::ostream& operator<<(std::ostream& out, const AForm& info);

#endif
