#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "default";
	this->Hitpoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "[Default Constructor created] " << "[FragTrap] [" << this->name << "]" << std::endl;
}
FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->Hitpoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "[Constructor created] " << "[FragTrap] [" << this->name << "]" << std::endl;
}
FragTrap::FragTrap(const FragTrap& Original)
{
	std::cout << "[Constructor copyed] " << "[FragTrap] [" << this->name << "]" << std::endl;
	*this = Original;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[Constructor destroyed] " << "[FragTrap] [" << this->name << "]" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	if(this != &copy)
	{
		std::cout << "[Assignment operator] [FragTrap]" << std::endl;
		this->name = copy.getName();
		this->Hitpoints = copy.getEnergyPoints();
		this->EnergyPoints = copy.getEnergyPoints();
		this->AttackDamage = copy.getAttackDamage();
	}
	return(*this);
}

void FragTrap::highFivesGuys(void)
{
	if(this->Hitpoints <= 0)
			std::cout << "[FragTrap " << this->name << " ]" << "is dead" << std::endl;
	else if(this->EnergyPoints <= 0)
		std::cout << "[FragTrap" << this->name << "]" << "is out of EnergyPoints" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->name << " is giving  highFivesGuys" << std::endl;
		this->EnergyPoints -= 1;
	}
}
// void FragTrap::attack(const std::string& target)
// {
// 	if (this->EnergyPoints > 0 && this->Hitpoints > 0)
// 		{
// 			this->EnergyPoints -= 1;
// 			std::cout << "-------attacks----start-----------------------------" <<std::endl;
// 			std::cout << "ScavTrap " << this->name << " attacks " << target<< ", causing " << this->AttackDamage << " points of damage!" << std::endl;
// 			std::cout << "-------attacks-------------------------------end--" <<std::endl;
// 		}
// 		else if(this->Hitpoints <= 0)
// 			std::cout << "[ScavTrap " << this->name << " ]" << "is dead" << std::endl;
// 		else if(this->EnergyPoints <= 0)
// 			std::cout << "[ScavTrap" << this->name << "]" << "is out of EnergyPoints" << std::endl;
// }
