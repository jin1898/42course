#include "Dog.hpp"

Dog::Dog(void) : type("dog")
{
	std::cout << "[Default Constructor created]" << "[Dog]" << this->type << std::endl;
}
Dog::Dog(const Dog& original)
{
	*this = original;
	std::cout << "[Constructor created][Dog]" << this->type << std::endl;
}
Dog& Dog::operator=(const Dog& original)
{
	if(this != &original)
	{
		std::cout << "[Assignment operator] [Dog]" << std::endl;
		this->type = original.type;
	}
	return(*this);
}
Dog:: ~Dog(void)
{
	std::cout << "[Constructor destroyed]" << "[Dog] [" << this->type << "]" << std::endl;
}
void Dog::makeSound(void) const
{
	std::cout << "[Dog] : Bark!Bark!" << std::endl;
}
const std::string& Dog::getType(void) const
{
	return(this->type);
}

void Dog::setType(const std::string& type)
{
	this->type = type;
}
