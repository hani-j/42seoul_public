#include "Harl.hpp"

int main (int argc, char **argv)
{
    Harl harl = Harl();

    if (argc != 2)
    {
        std::cerr << "Argument Error" << std::endl;
        return (1);
    }
    harl.complain(argv[1]);

}
