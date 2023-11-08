#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& Original);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& copy);
		//--ex00--start-
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		int getHitpoints(void) const;
		int getEnergyPoints(void) const;
		int getAttackDamage(void) const;
		//--ex00--end-
	private:
		std::string name;
		unsigned int Hitpoints; //체력
		unsigned int EnergyPoints;
		unsigned int AttackDamage;
};

#endif
