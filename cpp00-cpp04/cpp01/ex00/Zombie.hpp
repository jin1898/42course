#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		void announce(void);
		~Zombie(void);
	private:
		std::string name;
};
		void randomChump( std::string name );
		Zombie* newZombie( std::string name );

#endif
