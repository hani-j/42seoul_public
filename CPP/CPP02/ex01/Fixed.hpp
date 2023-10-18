#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _rawbits;
		static const int _literal = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &f);
		Fixed &operator= (const Fixed &f);

		Fixed(const int integer);
		Fixed(const float float_num);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
