#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	for(int i = 1; i < ac ; i++){
		for(int j = 0; av[i][j]; j++){
			if (97 <= av[i][j] && av[i][j] <= 122)
				std::cout << (char)(av[i][j] - 32);
			else if ((65 <= av[i][j] && av[i][j] <= 90) || av[i][j] == ' ')
				std::cout << av[i][j];
			else
				continue;
		}
		std::cout << ' ';
	}
	return(0);
}