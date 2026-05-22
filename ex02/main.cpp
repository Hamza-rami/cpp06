#include "functions.hpp"
#include <ctime>
#include <iostream>



int main()
{
    srand(time(NULL));
    Base *ddd = generate();
    identify(ddd);
    identify(*ddd);
    delete ddd;
    return 0;
}