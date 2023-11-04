#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *H = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		H[i].input_name(name);
	}
	return(H);
}
