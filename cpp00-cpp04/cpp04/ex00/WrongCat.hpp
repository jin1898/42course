#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& original);
		WrongCat& operator=(const WrongCat& original);
		~WrongCat(void);

		void makeSound(void) const;
		void setType(const std::string& type);
		const std::string& getType(void) const;

	private:
		std::string type;
};

#endif
