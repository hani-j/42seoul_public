#include "Data.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks convert");
// }

int main (void)
{
    // atexit(leaks);
    Data* data = new Data(42);
    uintptr_t uintptr;

    std::cout << "data        : " << data << std::endl; // 0x252352352
    std::cout << "data's Num  : " << data->getNum() << std::endl; // 42
    
    uintptr = serialize(data);
    std::cout << "uintptr     : " << uintptr << std::endl; // 521241241531241124

    std::cout << "rdata       : " << deserialize(uintptr) << std::endl; // 0x252352352
    std::cout << "rdata's Num : " << deserialize(uintptr)->getNum() << std::endl; // 42

    delete data;
}
