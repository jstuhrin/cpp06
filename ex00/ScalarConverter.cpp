
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

  bool isChar(const std::string& input)
  {
    return input.size() == 1;
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
    c = input[i];
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    i = static_cast<int>(c);
  }

  void handleFloat(const std::string& input, char& c, float& f, double& d, int& i)
  {
    std::istringstream iss();
    iss >> f;
    c = static_cast<char>(f);
    d = static_cast<double>(f);
    i = static_cast<int>(f);
  }

  void handleDouble(const std::string& input, char& c, float& f, double& d, int& i)
  {
    std::istringstream iss;
    iss >> d;
    c = static_cast<char>(d);
    f = static_cast<float>(d);
    i = static_cast<int>(d);
  }

  void handleInteger(const std::string& input, char& c, float& f, double& d, int& i)
  {
    
  }
}

void ScalarConverter::convert(std::string input)
{
  if (input.empty())
  {
    std::cout << "Input is empty string\n";
    return;
  }
  if (!isDisplayable(input))
  {
    return;
  }

  char c;
  float f;
  double d;
  int i;


}