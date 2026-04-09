#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t i = reinterpret_cast<uintptr_t>(ptr);
    return i;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *h = reinterpret_cast<Data*>(raw);
    return h;
}