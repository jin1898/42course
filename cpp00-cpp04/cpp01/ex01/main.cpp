#include "Zombie.hpp"

int	main(void)
{
	int	size;

	size = 20;
	Zombie *horde = zombieHorde(size, "Zom");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}
