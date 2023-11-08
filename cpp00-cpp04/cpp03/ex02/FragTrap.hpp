#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& Original);
		FragTrap& operator=(const FragTrap& copy);
		~FragTrap(void);
		void highFivesGuys(void);
		// void attack(const std::string& target);
};

#endif
