
#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
  if (argc > 1)
  {
     return ScalarConverter::convert(argv[1]);
  }
  std::cout << "please provide one argument\n";
  return 1;
}