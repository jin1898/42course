#include <iostream>

class Weapon
{
	public:
		const std::string getType();
		void setType(std::string newtype);
		Weapon(std::string word);
	private:
		std::string name;
};
