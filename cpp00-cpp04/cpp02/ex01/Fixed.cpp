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

Fixed::Fixed(const int number) : number(number << Fixed::bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : number(static_cast<int>(roundf(number * (1 << Fixed::bit))))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->number) / (1 << Fixed::bit);
}

int Fixed::toInt(void) const
{
	return this->number >> Fixed::bit;
}

std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed)
{
	return ofs << fixed.toFloat();
}

