#include "Weapon.hpp"

const std::string Weapon::getType()
{
	return (this->name);
}
void Weapon::setType(std::string newtype)
{
	this->name = newtype;
}
Weapon::Weapon(std::string word)
{
	this->name = word;
}
