#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->Hitpoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->Hitpoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "[ScavTrap" << this->name << " constructor called]" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& Original)
{
	std::cout << "[Constructor copyed] " << "[ClapTrap] [" << this->name << "]" << std::endl;
	*this = Original;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	if(this != &copy)
	{
		std::cout << "[Assignment operator] [ScavTrap]" << std::endl;
		this->name = copy.getName();
		this->Hitpoints = copy.getEnergyPoints();
		this->EnergyPoints = copy.getEnergyPoints();
		this->AttackDamage = copy.getAttackDamage();
	}
	return(*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[Constructor destroyed] " << "[ScavTrap] [" << this->name << "]" << std::endl;
}
void ScavTrap::guardGate(void)
{
	if(this->Hitpoints <= 0 || this-> EnergyPoints <= 0)
		std::cout << "[ScavTrap " << this->name << " ]" << "is dead" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " has entered gate guard mode" << std::endl;
		this->EnergyPoints -= 1;
	}
}
