#include <vector>
#include <iostream>
#include <poll.h>

int main () {
    
    struct pollfd   _poll[100];
    struct pollfd   p;
    struct pollfd   p1;
    std::vector<struct pollfd> _poll_vec;
    std::vector<struct pollfd>::iterator _it;

    for (int i = 0; i < 5; i++)
    {
        std::cout << &_poll[i] << std::endl;
    }
    p.fd = 0;
    p.events = POLLIN;
    p1.fd = 0;
    p1.events = POLLIN;
    _poll_vec.push_back(p);
    _poll_vec.push_back(p1);
    _poll_vec.push_back(p1);

    _it = _poll_vec.begin();
    while (_it != _poll_vec.end())
    {
        std::cout << &(*_it) << std::endl;
        ++_it;
    }
    

}