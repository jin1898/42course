#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& original);
		WrongAnimal& operator=(const WrongAnimal& original);
		virtual ~WrongAnimal(void);
		virtual void makeSound(void) const;

		virtual const std::string& getType(void) const;
		void setType(const std::string& type);
	protected:
		std::string type;
};
#endif
