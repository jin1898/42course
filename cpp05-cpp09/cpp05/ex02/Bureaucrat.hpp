#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private :
		int grade;
		const std::string name;
	public :
		//---OCCF---start-
		Bureaucrat();
		Bureaucrat(const Bureaucrat & copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& copy);
		//---OCCF---end-
		Bureaucrat(int grade, std::string name);

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
