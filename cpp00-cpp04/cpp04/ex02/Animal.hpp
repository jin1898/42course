#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>
class Animal
{
	public:
		Animal(void);
		Animal(const Animal& original);
		Animal& operator=(const Animal& original);
		virtual ~Animal(void);
		virtual void makeSound(void) const = 0;

		virtual const std::string& getType(void) const;
		void setType(const std::string& type);

		virtual Brain& getBrain(void) const = 0;
	protected:
		std::string type;
};
#endif
