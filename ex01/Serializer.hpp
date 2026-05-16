#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

#include "data.hpp"

class Serializer
{
  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

  private:
    Serializer(); // declared privately, and not implemented
};

#endif