#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name): name(name), weapontype(NULL)
{
	std::cout << "HumanB " << this->name << " created" << std::endl;
}

void HumanB::attack(void)
{
	std::cout << this->name << " : attacks with their" << this->weapontype->getType();
}
void HumanB::setWeapon(Weapon &weap)
{
	this->weapontype = &weap;
}
