#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentalPardonForm : public AForm
{
	private:
	std::string target;

	public :
		//--OCCF-start-
		PresidentalPardonForm();
		PresidentalPardonForm(const PresidentalPardonForm & copy);
		PresidentalPardonForm &operator=(const PresidentalPardonForm & copy);
		~PresidentalPardonForm();
		//--OCCF-end-

		std::string getTarget();
		PresidentalPardonForm(std::string target);
		void execute(Bureaucrat const & executer) const;
};

#endif
