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

		bool operator>(const Fixed& fixed);
		bool operator<(const Fixed& fixed);
		bool operator>=(const Fixed& fixed);
		bool operator<=(const Fixed& fixed);
		bool operator==(const Fixed& fixed);
		bool operator!=(const Fixed& fixed);
		Fixed operator+(const Fixed& fixed);
		Fixed operator-(const Fixed& fixed);
		Fixed operator*(const Fixed& fixed);
		Fixed operator/(const Fixed& fixed);
		Fixed& operator++(void);
		Fixed& operator--(void);
		const Fixed operator++(int);
		const Fixed operator--(int);
		Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed, const Fixed& fixed2);
		Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

};
	std::ostream& operator<<(std::ostream& ofs, const Fixed& fixed);

#endif
