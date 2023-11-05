#include "Zombie.hpp"

int	main(void)
{
	Zombie stack ("st");
	Zombie *heap = new Zombie("heap");

	randomChump("rad");
	stack.announce();
	heap->announce();
	delete heap;
	return(0);
}
