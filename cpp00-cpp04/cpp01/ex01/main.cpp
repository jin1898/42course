#include "Zombie.hpp"

void a()
{
	system("leaks -q zombie01");
}

int	main(void)
{
	int	size;
	atexit(a);
	size = 20;
	Zombie *horde = zombieHorde(size, "Zom");
	for (int i = 0; i < size; i++)
	{
		std::cout << '[' << i << ']';
		horde[i].announce();
	}

	delete [] horde;
}
