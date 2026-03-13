#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    int a = rand() % 3;
    if (a == 1)
        return new A;
    else if (a == 2)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    A* aaaa =  dynamic_cast<A*>(p);
    if (aaaa)
    {
        std::cout << "it's A\n";
        return;
    }
    B* bbbb =  dynamic_cast<B*>(p);
    if (bbbb)
    {
        std::cout << "it's B\n";
        return;
    }
    C* cccc =  dynamic_cast<C*>(p);
    if (cccc)
    {
        std::cout << "it's C\n";  
        return;
    }
}


void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "it's A\n";
        return;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "it's B\n";
        return;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
        try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "it's C\n";
        return;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
}


int main()
{
    srand(time(NULL));
    Base *ddd = generate();
    identify(ddd);
    identify(*ddd);
    delete ddd;
    return 0;
}
