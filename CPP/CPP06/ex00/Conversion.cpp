#include "Conversion.hpp"

Conversion::Conversion() : _str("default") {}
Conversion::~Conversion() {}
Conversion::Conversion(const Conversion& obj) {*this = obj;}
Conversion& Conversion::operator=(const Conversion& obj) 
{
	if (this != &obj)
		this->_str = obj._str;
	return (*this);
}

Conversion::Conversion(std::string str) : _str(str)
{
}

void Conversion::checkLiterals()
{
	bool check = false;

	if (checkChar())
		check = true;
	if (checkInt())
		check = true;
	if (checkFloat())
		check = true;
	if (checkDouble())
		check = true;
	if (check == false)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
	}
}
bool Conversion::checkChar()
{
	if (_str.length() == 1 && !isdigit(static_cast<char>(_str[0])))
	{
		_cStr = static_cast<char>(_str[0]);
		_iStr = static_cast<int>(_cStr);
		_fStr = static_cast<float>(_cStr);
		_dStr = static_cast<double>(_cStr);
		toLiterals();
		return (true);
	}
	return (false);
}
bool Conversion::checkInt()
{
	int tmp = atoi(_str.c_str());
	std::stringstream ss;
    ss << tmp;
	if (ss.str() != _str && _str[0] != '+') 
		return (false);
	if (_str.find('.') == std::string::npos && tmp >= INT_MIN && tmp <= INT_MAX)
	{
		_iStr = tmp;
		_cStr = static_cast<char>(_iStr);
		_fStr = static_cast<float>(_iStr);
		_dStr = static_cast<double>(_iStr);
		toLiterals();
		return (true);
	}
	return (false);
}
bool Conversion::checkFloat()
{
	char *pos = NULL;
	double tmp = strtod(_str.c_str(), &pos);
	if (((*pos && !std::strcmp(pos, "f")) && (_str.find('.') != std::string::npos && _str.find('f') == _str.length() - 1)) || !_str.compare("inff") || (!_str.compare("-inff") || !_str.compare("+inff") || !_str.compare("nanf")))
	{
		_dStr = tmp;
		_fStr = static_cast<float>(_dStr);
		_iStr = static_cast<int>(_fStr);
		_cStr = static_cast<char>(_fStr);
		_dStr = static_cast<double>(_fStr);
		toLiterals();
		return (true);
	}
	return (false);
}
bool Conversion::checkDouble()
{
	char *pos = NULL;
	double tmp = strtod(_str.c_str(), &pos);
	if (*pos && std::strcmp(pos, "\0"))
		return (false);
	if (_str.find('.') != std::string::npos || !_str.compare("inf") || !_str.compare("-inf") || !_str.compare("+inf") || !_str.compare("nan"))
	{
		_dStr = tmp;
		_iStr = static_cast<int>(_dStr);
		_cStr = static_cast<char>(_dStr);
		_fStr = static_cast<float>(_dStr);
		toLiterals();
		return (true);
	}
	return (false);
}

void Conversion::toLiterals()
{
	this->toChar();
	this->toInt();
	this->toFloat();
	this->toDouble();
}
void Conversion::toChar()
{
	try
	{
		std::cout << "char: " ;
		if (!_str.compare("nan") || !_str.compare("nanf") || !_str.compare("inf") || !_str.compare("inff") || !_str.compare("+inf") || !_str.compare("+inff") || !_str.compare("-inf") || !_str.compare("-inff") || _dStr < CHAR_MIN || _dStr > CHAR_MAX)
			throw ImpossibleException();
		if (std::isprint(_cStr))
			std::cout << '\'' << this->_cStr << '\'' << std::endl;
		else
			throw NonDisplayableException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void Conversion::toInt()
{
	try
	{
		std::cout << "int: ";
		if (!_str.compare("nan") || !_str.compare("nanf") || !_str.compare("inf") || !_str.compare("inff") || !_str.compare("+inf") || !_str.compare("+inff") || !_str.compare("-inf") || !_str.compare("-inff") || _dStr < INT_MIN || _dStr > INT_MAX)
			throw ImpossibleException();
		std::cout << this->_iStr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void Conversion::toFloat()
{
	try
	{
		std::cout << "float: ";
		std::cout << this->_fStr;
		int tmp = atoi(_str.c_str());
		std::stringstream ss;
		ss << tmp;
		if (ss.str().size() < 7 && _iStr - _dStr == 0)
        	std::cout << ".0f" << std::endl;
    	else
        	std::cout << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void Conversion::toDouble()
{
	try
	{
		std::cout << "double: " ;
		std::cout << this->_dStr;
		int tmp = atoi(_str.c_str());
		std::stringstream ss;
		ss << tmp;
		if (ss.str().size() < 7 && _iStr - _dStr == 0)
        	std::cout << ".0";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char* Conversion::NonDisplayableException::what() const throw()
{
	return ("Non displayable");
}
const char* Conversion::ImpossibleException::what() const throw()
{
	return ("Impossible");
}
