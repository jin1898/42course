#include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}
Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	return;
}
void	randomChump(std::string name)
{
	Zombie zon(name);
	zon.announce();
}
Zombie* newZombie(std::string name)
{
	return(new Zombie(name));
}
void Zombie::input_name(std::string name)
{
	this->name = name;
}
void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

