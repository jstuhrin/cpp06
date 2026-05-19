
#include <cassert>

#include "Serializer.hpp"

int main()
{
  Data data;

  Data* ptr = Serializer::deserialize(Serializer::serialize(&data));

  std::cout << &data << " == " << ptr << ": " << (ptr == &data ? "true\n" : "false\n");

  assert(&data == ptr);
  assert(data.c == ptr->c && data.i == ptr->i && data.f == ptr->f && data.c == ptr->d);


  {
    uintptr_t uPtr = Serializer::serialize(&data);

    std::cout << uPtr << '\n';

    // this will not compile
    // std::cout << "char: " << uPtr.c << '\n';
  }

  return 0;
}