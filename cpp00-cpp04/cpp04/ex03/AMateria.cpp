#include "AMateria.hpp"

AMateria::AMateria(void) : type("defualt")
{
	std::cout << "[Default Constructor created]" << "[AMateria]" << std::endl;
}
AMateria::AMateria(std::string const & type) : type(type)
{

}
