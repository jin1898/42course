#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string target;
	public :
	//--OCCF--start-
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm & copy);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	//--OCCF--end-

	RobotomyRequestForm(std::string target);
	void execute(Bureaucrat const &executer)const;
};

#endif
