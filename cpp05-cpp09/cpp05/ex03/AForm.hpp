#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
        //기반클래스에서 예외 케이스 만들고 이용하기-start-
        class FNotSigned : public std::exception
        {
            public:
            virtual const char *what()const throw();
        };
        //기반클래스에서 예외 케이스 만들고 이용하기-end-
};
    std::ostream& operator<<(std::ostream& out, const AForm& info);

#endif
