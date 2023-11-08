#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "[Constructor created] " << "[ClapTrap] [" << this->name << "]" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "[Constructor created] " << "[ClapTrap] [" << this->name << "]" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "[Constructor destroyed] " << "[ClapTrap] [" << this->name << "]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& Original)
{
	std::cout << "[Constructor copyed] " << "[ClapTrap] [" << this->name << "]" << std::endl;
	*this = Original;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	if(this != &copy)
	{
		std::cout << "[Assignment operator] [ClapTrap]" << std::endl;
		this->name = copy.getName();
		this->Hitpoints = copy.getEnergyPoints();
		this->EnergyPoints = copy.getEnergyPoints();
		this->AttackDamage = copy.getAttackDamage();
	}
	return(*this);
}

//---ex00 --start
void ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints > 0 && this->Hitpoints > 0)
	{
		this->EnergyPoints -= 1;
		std::cout << "-------attacks----start-----------------------------" <<std::endl;
		std::cout << "ClapTrap " << this->name << " attacks " << target<< ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		std::cout << "-------attacks-------------------------------end--" <<std::endl;
		//목표 체력이 1줄어야한다.
	}
	else if(this->Hitpoints <= 0)
		std::cout << "[ClapTrap " << this->name << " ]" << "is dead" << std::endl;
	else if(this->EnergyPoints <= 0)
		std::cout << "[ClapTrap" << this->name << "]" << "is out of EnergyPoints" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->EnergyPoints > 0 && this->Hitpoints > 0)
	{
		std::cout << "-------beRepaired----start-----------------------------" <<std::endl;
		std::cout << "ClapTrap " << this->name << " healed " << amount << " point(s)." << std::endl;
		std::cout << "-------beRepaired-----------------------------end----" <<std::endl;
		this->EnergyPoints -= 1;
		this->Hitpoints += amount;
	}
	else if(this->Hitpoints <= 0)
		std::cout << "[" << this->name << "]" << "[ClapTrap]is dead" << std::endl;
	else if(this->EnergyPoints <= 0)
		std::cout << "[" << this->name << "]" << "[ClapTrap] is out of EnergyPoints" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->Hitpoints > 0)
	{
		std::cout << "-------takeDamage----start-----------------------------" <<std::endl;
		std::cout << "ClapTrap " << this->name << " took " << amount << " point(s) of damage!" << std::endl;
		std::cout << "-------takeDamag-----------------------------end----" <<std::endl;
		this->Hitpoints -= amount;
	}

	else
	{
		std::cout << "-------takeDamage----start-----------------------------" <<std::endl;
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
		std::cout << "-------takeDamag-----------------------------end----" <<std::endl;
	}
}
//---ex00 --end
//get함수 --start-
std::string ClapTrap::getName(void) const
{
	return(this->name);
}

int ClapTrap::getHitpoints(void)const
{
	return(this->Hitpoints);
}

int ClapTrap::getEnergyPoints(void)const
{
	return(this->EnergyPoints);
}
int ClapTrap::getAttackDamage(void)const
{
	return(this->AttackDamage);
}
//get함수 --end-

