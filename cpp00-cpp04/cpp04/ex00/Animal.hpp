#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
class Animal
{
	public:
		Animal(void);
		Animal(const Animal& original);
		Animal& operator=(const Animal& original);
		virtual ~Animal(void);
		virtual void makeSound(void) const;

		virtual const std::string& getType(void) const;
		void setType(const std::string& type);
	protected:
		std::string type;
};
#endif
