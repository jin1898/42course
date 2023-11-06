#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
class HumanA
{
	public:
		HumanA(std::string name, Weapon &a);
		~HumanA(void);
		void attack(void);
	private:
		std::string name;
		Weapon& weapon;
};
#endif
