#include "Data.hpp"

Data::Data() : _num(0) {}
Data::~Data() {}
Data::Data(const Data& obj) : _num(obj._num) {}
Data& Data::operator=(const Data& obj) 
{
    if (this != &obj)
        this->_num = obj._num;
    return (*this);
}

Data::Data(int num) : _num(num) {}
int Data::getNum() const { return (this->_num); }


uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
