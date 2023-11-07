#include "Fixed.hpp"

const int	Fixed::bit = 8;

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->number);
}

void Fixed::setRawBits( int const raw )
{
	this->number = raw;
}
Fixed::Fixed(void) : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& OriginalFunction)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = OriginalFunction;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &fixed)
		this->number = fixed.getRawBits();
	return(*this);
}
