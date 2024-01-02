#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentalPardonForm : public AForm
{
	public :
		 void execute(Bureaucrat const & executer) const;
};

#endif
