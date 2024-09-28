#ifndef CURE_HPP
#define CURE_HPP
#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &copy);
		~Cure(void);
		Cure const	&operator=(Cure const &copy);

		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};
#endif
