#include "Dog.hpp"

Dog::Dog(void) : type("dog")
{
	this->brain = new Brain();
	std::cout << "[Default Constructor created]" << "[Dog]" << this->type << std::endl;
}
Dog::Dog(const Dog& original)
{
	this->brain = new Brain(*original.brain);
	std::cout << "[Constructor created][Dog]" << this->type << std::endl;
}
Dog& Dog::operator=(const Dog& original)
{
	if(this != &original)
	{
		std::cout << "[Assignment operator] [Dog]" << std::endl;
		this->type = original.type;
		*this->brain = *original.brain;
	}
	return(*this);
}
Dog:: ~Dog(void)
{
	delete this->brain;
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
void Dog::setBrain(const Brain &brain)
{
	*this->brain = brain;
}
Brain &Dog::getBrain(void) const
{
	return (*this->brain);
}

