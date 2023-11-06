#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapontype;
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon &weap);
};
#endif