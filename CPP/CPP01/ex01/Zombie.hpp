#ifndef ZOMIBE_HPP
# define ZOMIBE_HPP

# include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
