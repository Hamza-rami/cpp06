#include "Serializer.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t t = reinterpret_cast<uintptr_t>(ptr);
    return t;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *h = reinterpret_cast<Data*>(raw);
    return h;
}