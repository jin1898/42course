#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria(void);
		AMateria(const AMateria& original);
		AMateria& operator=(const AMateria& original);
		~AMateria(void);

		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
}

#endif
