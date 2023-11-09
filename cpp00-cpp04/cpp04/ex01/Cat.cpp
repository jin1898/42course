#include "Cat.hpp"

Cat::Cat(void) : type("cat")
{
	std::cout << "[Default Constructor created]" << "[Cat]" << this->type << std::endl;
}
Cat::Cat(const Cat& original)
{
	*this = original;
	std::cout << "[Constructor created][Cat]" << this->type << std::endl;
}
Cat& Cat::operator=(const Cat& original)
{
	if(this != &original)
	{
		std::cout << "[Assignment operator] [Cat]" << std::endl;
		this->type = original.type;
	}
	return(*this);
}
Cat:: ~Cat(void)
{
	std::cout << "[Constructor destroyed]" << "[Cat] [" << this->type << "]" << std::endl;
}
void Cat::makeSound(void) const
{
	std::cout << "[Cat] : Meow!" << std::endl;
}
const std::string& Cat::getType(void) const
{
	return(this->type);
}

void Cat::setType(const std::string& type)
{
	this->type = type;
}
