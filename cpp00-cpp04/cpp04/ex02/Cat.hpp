#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& original);
		Cat& operator=(const Cat& original);
		~Cat(void);

		void makeSound(void) const;
		void setType(const std::string& type);
		const std::string& getType(void) const;

		void setBrain(const Brain &brain);
		Brain &getBrain(void) const;
	private:
		Brain	*brain;
		std::string type;
};

#endif
