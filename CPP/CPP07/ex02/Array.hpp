#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private :
		T *_array;
		unsigned int _len;

		Array() : _array(new T[0]), _len(0){};
	public :
		~Array() { delete[] this->_array; };
		Array(const Array& obj) : _len(obj._len)
		{
			_array = new T[obj._len];
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = obj._array[i];
		};
		Array& operator=(const Array& obj)
		{
			if (this != &obj)
			{
				delete[] _array;
				_array = new T[obj._len];
				_len = obj._len;
				for (unsigned int i = 0; i < _len; i++)
					_array[i] = obj._array[i];
			}
			return (*this);
		};

		Array(unsigned int len) : _len(len)
		{
			if (len < 0)
				throw OutOfBoundException();
			_array = new T[len];
		};
		
		T& operator[](unsigned int idx)
		{
			if(idx < 0 || idx >= _len)
			{
				throw OutOfBoundException();
			}
			return _array[idx];
		};

		unsigned int size(void) const
		{
			return (this->_len);
		};

		class OutOfBoundException : public std::exception
		{
			public :
				const char* what() const throw()
				{
					return ("Out Of Bound");
				};
		};

		T* getArray()
		{
			return (this->_array);
		}
};

#endif
