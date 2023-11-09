#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Default Constructor created]" << "[Brain]" << std::endl;
}
Brain::Brain(const Brain& original)
{
	*this = original;
	std::cout << "[Constructor created][Brain]" << std::endl;
}
const Brain& Brain::operator=(const Brain& original)
{
	// if(this != &original)
	// {
		std::cout << "[Assignment operator] [Brain]" << std::endl;
		std::copy(original.ideas, original.ideas + 100, this->ideas);
	// }
	return(*this);
}

Brain:: ~Brain(void)
{
	std::cout << "[Constructor destroyed]" << "[Brain]" << std::endl;
}
const std::string& Brain::getIdea(const int& index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return(this->ideas[0]);
}

void Brain::setIdea(const std::string &idea, const int &index)
{
	if(index >= 0 && index < 100)
		this->ideas[index] = idea;
}
