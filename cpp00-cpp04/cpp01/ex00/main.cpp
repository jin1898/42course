#include "Zombie.hpp"

int	main(void)
{
	Zombie *heap;
	{
		Zombie stack("st");
		heap = new Zombie("heap");
		randomChump("rad");
		stack.announce();
	}
	heap->announce();
	delete heap;

	return(0);
}
