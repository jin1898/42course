#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "[Default Constructor created]" << "[WrongAnimal]" << this->type << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
	*this = original;
	std::cout << "[Constructor created][WrongAnimal]" << this->type << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
	if(this != &original)
	{
		std::cout << "[Assignment operator] [WrongAnimal]" << std::endl;
		this->type = original.type;
	}
	return(*this);
}

WrongAnimal:: ~WrongAnimal(void)
{
	std::cout << "[Constructor destroyed]" << "[WrongAnimal] [" << this->type << "]" << std::endl;
}
void WrongAnimal::makeSound(void) const
{
	std::cout << "[WrongAnimal] : ..." << std::endl;
}
const std::string& WrongAnimal::getType(void) const
{
	return(this->type);
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}
