
#include "ScalarConverter.hpp"

namespace
{
  void traverseNum(const std::string& input, std::size_t& i)
  {
    if (input[i] == '-' || input[i] == +)
    {
      ++i;
    }
    while (std::isdigit(input[i]))
    {
      ++i;
    }
    if (input[i] == '.')
    {
      ++i;
    }
    while (std::isdigit(input[i]))
    {
      ++i;
    }
  }

  bool isFloat(const std::string& input)
  {
    if (input.back() != 'f')
    {
      return false;
    }
    std::size_t i = 0;
    traverseNum(input, i);
    if (i != input.size() - 2)
    {
      return false;
    }
    return true;
  }

  bool isDouble(const std::string& input)
  {
    std::size_t i = 0;
    traverseNum(input, i);
    if (i != input.size() - 1)
    {
      return false;
    }
    return true;
  }

  bool isInt(const std::string& input)
  {
    std::size_t i = 0;
    traverseNum(input, i);
    if (i != input.size() - 1)
    {
      return false;
    }
    return true;
  }

  bool isChar(const std::string& input)
  {
    if (!isalpha(input[0]))
    {
      return false;
    }
    if (input.size() > 1)
    {
      return false;
    }
    return true;
  }
}

void ScalarConverter::convert(std::string input)
{




  std::cout << "char: " << c << "\nint: " << i << "\nfloat: " << f << "\ndouble: " << d << "\n";
}