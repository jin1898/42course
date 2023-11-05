
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &a) : name(name), weapontype(a)
{
	std::cout << "HumanA" << this->name << "created" << std::endl;
	std::cout << a.getType() << std::endl;

}
void HumanA::attack()
{
	std::cout << this->name << " : attacks with their" << this->weapontype.getType();
}
