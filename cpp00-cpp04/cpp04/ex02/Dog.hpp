#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& original);
		Dog& operator=(const Dog& original);
		~Dog(void);

		void setType(const std::string& type);
		const std::string& getType(void) const;
		void makeSound(void) const;

		void setBrain(const Brain &brain);
		Brain &getBrain(void) const;

	private:
		Brain *brain;
		std::string type;
};

#endif
