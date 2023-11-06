
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &a) : name(name), weapon(a)
{
	std::cout << "HumanA" << this->name << "created" << std::endl;
	std::cout << a.getType() << std::endl;

}

HumanA::~HumanA(void)
{
	std::cout << "HumanA" << this->name << "destroyed" << std::endl;
}
void HumanA::attack()
{
	std::cout << this->name << " : attacks with their " << this->weapon.getType();
	std::cout << std::endl;
}
