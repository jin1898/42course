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

	private:
		std::string type;
};

#endif
