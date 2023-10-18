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
		Fixed& operator= (const Fixed &f);

		Fixed(const int integer);
		Fixed(const float float_num);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool operator> (const Fixed &f) const;
		bool operator< (const Fixed &f) const;
		bool operator>= (const Fixed &f) const;
		bool operator<= (const Fixed &f) const;
		bool operator== (const Fixed &f) const;
		bool operator!= (const Fixed &f) const;

		Fixed operator+ (const Fixed &f) const;
		Fixed operator- (const Fixed &f) const;
		Fixed operator* (const Fixed &f) const;
		Fixed operator/ (const Fixed &f) const;

		Fixed& operator++(void);
		const Fixed operator++(int);
		Fixed& operator--(void);
		const Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
