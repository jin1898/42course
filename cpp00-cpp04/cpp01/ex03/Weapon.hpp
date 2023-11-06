#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		const std::string getType();
		void setType(std::string newtype);
		Weapon(std::string word);
		~Weapon();
	private:
		std::string type;
};

#endif
