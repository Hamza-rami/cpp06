#include "functions.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>



int main()
{
    srand(std::time(NULL));
    Base *ddd = generate();
    identify(ddd);
    identify(*ddd);
    delete ddd;
    return 0;
}