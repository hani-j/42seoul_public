#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
