#include "Weapon.hpp"

const std::string Weapon::getType()
{
	return (this->type);
}
void Weapon::setType(std::string newtype)
{
	this->type = newtype;
}
Weapon::Weapon(std::string word): type(word)
{
}
Weapon::~Weapon()
{
}
