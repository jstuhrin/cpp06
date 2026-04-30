
#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
  if (argc > 1)
  {
    ScalarConverter::convert(argv[1]);
  }
  else
  {
    std::cout << "please provide one argument\n";
  }
  return 0;
}