#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon &weap);
		~HumanB(void);
	private:
		std::string name;
		Weapon *weapon;
};
#endif
