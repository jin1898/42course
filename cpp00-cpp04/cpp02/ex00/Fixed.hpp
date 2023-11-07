#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
};

#endif
