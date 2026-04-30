
#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
  std::stringstream ss;
  ss.str(input);
  char c;
  ss >> c;
  ss.clear();

  ss.str(input);
  int i;
  ss >> i;
  ss.clear();

  ss.str(input);
  float f;
  ss >> f;
  ss.clear();

  ss.str(input);
  double d;
  ss >> d;
  ss.clear();

  std::cout << "char: " << c << "\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << "\n";
}