#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int number;
		static const int bit;
	public:
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed();
		Fixed(const Fixed& OriginalFunction);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);
		Fixed(const int number);
		Fixed(const float numbr);
		float toFloat(void) const;
		int toInt(void) const;

};
	std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed);

#endif
