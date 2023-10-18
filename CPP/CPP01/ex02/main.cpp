#include <string>
#include <iostream>

int main (void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "---------- address ----------" << std::endl;
    std::cout << "string's address : " << &str << std::endl;
    std::cout << "stringPTR's address : " << stringPTR << std::endl;
    std::cout << "stringREF's address : " << &stringREF << std::endl;
    std::cout << std::endl;

    std::cout << "----------- value -----------" << std::endl;
    std::cout << "string's value : " << str << std::endl;
    std::cout << "stringPTR's value : " << *stringPTR << std::endl;
    std::cout << "stringREF's value : " << stringREF << std::endl;
}
