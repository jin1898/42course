#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
class HumanA
{
	public:
		HumanA(std::string name, Weapon &a);
		void attack();
	private:
		std::string name;
		Weapon &weapontype;
};
#endif