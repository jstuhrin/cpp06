
#include "ScalarConverter.hpp"

namespace
{
  bool isDisplayable(const std::string& input)
  {
    for (std::size_t i = 0; i < input.size(); ++i)
    {
      if (!std::isprint(static_cast<unsigned char>(input[0])))
      {
        std::cout << "Input contains non-printable char\n";
        return false;
      }
    }
    return true;
  }

  bool handleSpecialValues(const std::string& input)
  {
    if (input == "nan")
    {
      std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
      return true;
    }
    if (input == "+inf")
    {
      std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
      return true;
    }
    if (input == "-inf")
    {
      std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
      return true;
    }
    if (input == "nanf")
    {
      std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
      return true;
    }
    if (input == "+inff")
    {
      std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
      return true;
    }
    if (input == "-inff")
    {
      std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
      return true;
    }
    return false;
  }

  bool isChar(const std::string& input)
  {
    return input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0]));
  }

  bool isFloat(const std::string& input)
  {
    std::size_t i = 0;
    if (input[i] != '-' && input[i] != '+' && !std::isdigit(static_cast<unsigned char>(input[i])))
    {
      return false;
    }
    ++i;
    while (std::isdigit(static_cast<unsigned char>(input[i])))
    {
      ++i;
    }
    if (input[i++] != '.')
    {
      return false;
    }
    while (std::isdigit(static_cast<unsigned char>(input[i])))
    {
      ++i;
    }
    if (input[i] != 'f')
    {
      return false;
    }

    if (i != input.size() - 1)
    {
      return false;
    }
    return true;
  }

  bool isDouble(const std::string& input)
  {
    std::size_t i = 0;
    if (input[i] != '-' && input[i] != '+' && !std::isdigit(static_cast<unsigned char>(input[i])))
    {
      return false;
    }
    ++i;
    while (std::isdigit(static_cast<unsigned char>(input[i])))
    {
      ++i;
    }
    if (input[i++] != '.')
    {
      return false;
    }
    while (std::isdigit(static_cast<unsigned char>(input[i])))
    {
      ++i;
    }
    if (i != input.size())
    {
      return false;
    }
    return true;
  }

  bool isInt(const std::string& input)
  {
    std::size_t i = 0;
    if (input[i] != '-' && input[i] != '+' && !std::isdigit(static_cast<unsigned char>(input[i])))
    {
      return false;
    }
    ++i;
    while (std::isdigit(static_cast<unsigned char>(input[i])))
    {
      ++i;
    }
    if (i != input.size())
    {
      return false;
    }
    return true;
  }

  void handleChar(const std::string& input, char& c, float& f, double& d, int& i)
  {
    c = input[0];
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    i = static_cast<int>(c);
  }

  void handleFloat(const std::string& input, char& c, float& f, double& d, int& i)
  {
    std::istringstream iss;
    iss.str(input);
    iss >> f;
    c = static_cast<char>(f);
    d = static_cast<double>(f);
    i = static_cast<int>(f);
  }

  void handleDouble(const std::string& input, char& c, float& f, double& d, int& i)
  {
    std::istringstream iss;
    iss.str(input);
    iss >> d;
    c = static_cast<char>(d);
    f = static_cast<float>(d);
    i = static_cast<int>(d);
  }

  void handleInteger(const std::string& input, char& c, float& f, double& d, int& i)
  {
    std::istringstream iss;
    iss.str(input);
    iss >> i;
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
  }

  void print(const char& c, const float& f, const double& d, const int& i)
  {
    std::cout << "char: " << c << "\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << "\n";
  }
}

int ScalarConverter::convert(std::string input)
{
  if (input.empty())
  {
    std::cout << "Input is empty string\n";
    return 1;
  }
  if (!isDisplayable(input))
    return 1;
  if (handleSpecialValues(input))
    return 0;

  char c;
  float f;
  double d;
  int i;

  if (isChar(input))
    handleChar(input, c, f, d, i);
  else if (isFloat(input))
    handleFloat(input, c, f, d, i);
  else if (isDouble(input))
    handleDouble(input, c, f, d, i);
  else if (isInt(input))
    handleInteger(input, c, f, d, i);

  print(c, f, d, i);

  return 0;
}