#include "Cat.hpp"

Cat::Cat(void) : type("cat")
{
	this->brain = new Brain();
	std::cout << "[Default Constructor created]" << "[Cat]" << this->type << std::endl;
}
Cat::Cat(const Cat& original)
{
	this->brain = new Brain();
	*this = original;
	std::cout << "[Constructor created][Cat]" << this->type << std::endl;
}
Cat& Cat::operator=(const Cat& original)
{
	if(this != &original)
	{
		std::cout << "[Assignment operator] [Cat]" << std::endl;
		*this->brain = *original.brain;
	}
	return(*this);
}
Cat:: ~Cat(void)
{
	delete this->brain;
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
void Cat::setBrain(const Brain &brain)
{
	*this->brain = brain;
}
Brain &Cat::getBrain(void) const
{
	return (*this->brain);
}
