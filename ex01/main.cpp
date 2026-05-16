
#include "Serializer.hpp"

int main()
{
  Data data;

  Data* ptr = Serializer::deserialize(Serializer::serialize(&data));

  std::cout << &data << " == " << ptr << ": " << (ptr == &data ? "true\n" : "false\n");

  return 0;
}