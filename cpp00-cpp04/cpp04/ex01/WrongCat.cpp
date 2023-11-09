#include "WrongCat.hpp"

WrongCat::WrongCat(void) : type("wrongcat")
{
	std::cout << "[Default Constructor created]" << "[WrongCat]" << this->type << std::endl;
}
WrongCat::WrongCat(const WrongCat& original)
{
	*this = original;
	std::cout << "[Constructor created][WrongCat]" << this->type << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& original)
{
	if(this != &original)
	{
		std::cout << "[Assignment operator] [WrongCat]" << std::endl;
		this->type = original.type;
	}
	return(*this);
}
WrongCat:: ~WrongCat(void)
{
	std::cout << "[Constructor destroyed]" << "[WrongCat] [" << this->type << "]" << std::endl;
}
void WrongCat::makeSound(void) const
{
	std::cout << "[WrongCat] : Meow!" << std::endl;
}
const std::string& WrongCat::getType(void) const
{
	return(this->type);
}

void WrongCat::setType(const std::string& type)
{
	this->type = type;
}
