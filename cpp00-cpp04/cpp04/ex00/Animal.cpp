#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "[Default Constructor created]" << "[Animal]" << this->type << std::endl;
}
Animal::Animal(const Animal& original)
{
	*this = original;
	std::cout << "[Constructor created][Animal]" << this->type << std::endl;
}
Animal& Animal::operator=(const Animal& original)
{
	if(this != &original)
	{
		std::cout << "[Assignment operator] [Animal]" << std::endl;
		this->type = original.type;
	}
	return(*this);
}

Animal:: ~Animal(void)
{
	std::cout << "[Constructor destroyed]" << "[Animal] [" << this->type << "]" << std::endl;
}
void Animal::makeSound(void) const
{
	std::cout << "[Animal] : ..." << std::endl;
}
const std::string& Animal::getType(void) const
{
	return(this->type);
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}
