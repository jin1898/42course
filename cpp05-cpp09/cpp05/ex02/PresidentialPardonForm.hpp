#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
	std::string target;

	public :
		//--OCCF-start-
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm & copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm & copy);
		~PresidentialPardonForm();
		//--OCCF-end-

		std::string getTarget();
		PresidentialPardonForm(std::string target);
		void execute(Bureaucrat const & executer) const;
};

#endif
