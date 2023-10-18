#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <climits>
#include <cmath>

class Conversion
{
	private:
		std::string _str;
		int _iStr;
		char _cStr;
		float _fStr;
		double _dStr;
		Conversion();
	public:
		Conversion(std::string str);
		Conversion(const Conversion& obj);
		~Conversion();
		Conversion& operator=(const Conversion& obj);

		void checkLiterals();
		bool checkChar();
		bool checkInt();
		bool checkFloat();
		bool checkDouble();

		void toLiterals();
		void toChar();
		void toInt();
		void toFloat();
		void toDouble();

		class NonDisplayableException : public std::exception{
			public :
                const char* what() const throw();
        };
		class ImpossibleException : public std::exception{
			public :
                const char* what() const throw();
        };
};

#endif

