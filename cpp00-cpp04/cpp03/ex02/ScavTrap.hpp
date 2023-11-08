#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& Original);
		ScavTrap& operator=(const ScavTrap& copy);
		~ScavTrap(void);
		void guardGate(void);
};

#endif
