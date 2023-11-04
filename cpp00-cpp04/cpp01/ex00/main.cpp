#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z = newZombie("me");
	z->announce();
	randomChump("Chumped zom");
	delete z;
}
