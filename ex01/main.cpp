#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data* original = new Data();
    original->a = 42;

    uintptr_t raw = Serializer::serialize(original);
    Data* result = Serializer::deserialize(raw);
    
    std::cout << "original pointer: " << original << "\n";
    std::cout << "result pointer:   " << result << "\n";
    std::cout << "Raw:   " << raw << "\n";
    std::cout << "same?: " << (original == result ? "YES" : "NO") << "\n";
    std::cout << "data: " << result->a << "\n";

    delete original;
    return 0;
}