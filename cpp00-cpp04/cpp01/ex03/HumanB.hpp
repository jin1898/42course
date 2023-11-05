#include <iostream>

class HumanB
{
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon &weap);
	private:
		std::string name;
		Weapon *weapontype;
};
