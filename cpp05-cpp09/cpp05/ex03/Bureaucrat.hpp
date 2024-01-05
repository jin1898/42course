#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	//생성자 복사_생성자 소멸자 =오퍼레이터
	private :
		int grade;
		const std::string name;
	public :
		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat & copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& copy);

		const std::string getName() const;
		int getGrade() const;

		void increment();
		void decrement();
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
		void signForm(AForm & fInfo);
		void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& print);

#endif
