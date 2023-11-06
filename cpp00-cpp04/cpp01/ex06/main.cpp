#include "Harl.hpp"


int main(int ac, char **av)
{
	Harl H;

	if (ac == 1 || ac > 3)
		return (0);
	H.complain(av[1]);
}
