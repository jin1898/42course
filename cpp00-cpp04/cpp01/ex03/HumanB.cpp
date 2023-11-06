#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	std::cout << "---생성자 실행중----" << std::endl;
	std::cout << "HumanB " << this->name << " created" << std::endl;
	std::cout << "---생성자 실행완료----" << std::endl;
}

void HumanB::attack(void)
{
	if (this->weapon != NULL)
	{
		std::cout << this->name << " : attacks with their " << this->weapon->getType();
		std::cout << std::endl;
	}
}
void HumanB::setWeapon(Weapon &weap)
{
	this->weapon = &weap;
}
HumanB::~HumanB(void)
{
	std::cout << "---소멸자 실행중----" << std::endl;
	std::cout << "HumanB " << this->name << " destroyed" << std::endl;
	std::cout << "---소멸자 실행완료----" << std::endl;
}
