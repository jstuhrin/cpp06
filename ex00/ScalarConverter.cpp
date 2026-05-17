
#include "ScalarConverter.hpp"

namespace
{
  struct Data
  {
    char c;
    float f;
    double d;
    int i;

    bool cPossible;
    bool fPossible;
    bool dPossible;
    bool iPossible;

    std::string suffixFloat;
    std::string suffixDouble;

    Data()
      : cPossible(false)
      , fPossible(false)
      , dPossible(false)
      , iPossible(false)
    {}
  };

  void print(const Data& data)
  {
    std::cout << std::setprecision(309);
    std::cout << "char: ";
    if (!data.cPossible)
      std::cout << "impossible\n";
    else if (std::isprint(static_cast<unsigned char>(data.c)))
      std::cout << "'" << data.c << "'\n";
    else
      std::cout << "Non displayable\n";

    std::cout << "int: ";
    if (data.iPossible)
      std::cout << data.i << '\n';
    else
      std::cout << "impossible\n";
    
    std::cout << "float: ";
    if (data.fPossible)
      std::cout << data.f << data.suffixFloat << '\n';
    else
      std::cout << "impossible\n";
    
    std::cout << "double: ";
    if (data.dPossible)
      std::cout << data.d << data.suffixDouble << '\n';
    else
      std::cout << "impossible\n";
  }

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

  void setSuffix(Data& data)
  {
    data.suffixFloat = "f";

    std::stringstream ss;
    ss << data.f;
    std::string floatStr = ss.str();
    std::string::size_type posDot = floatStr.find('.');
    if (posDot == std::string::npos)
    {
      data.suffixFloat = ".0f";
    }

    ss.clear();
    ss << data.d;
    std::string doubleStr = ss.str();
    posDot = doubleStr.find('.');
    if (posDot == std::string::npos)
    {
      data.suffixDouble = ".0";
    }

    if (data.f == -std::numeric_limits<float>::infinity() || data.f == std::numeric_limits<float>::infinity())
    {
      data.suffixFloat = "f";
    }

    if (data.d == -std::numeric_limits<double>::infinity() || data.d == std::numeric_limits<double>::infinity())
    {
      data.suffixDouble = "";
    }
  }

  bool isAllDigits(const std::string& input, std::size_t start, std::size_t end)
  {
    for (std::size_t i = start; i < end; ++i)
    {
      if (!std::isdigit(static_cast<unsigned char>(input[i])))
      {
        return false;
      }
    }
    return true;
  }

  bool isChar(const std::string& input)
  {
    return input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0]));
  }

  bool isFloat(const std::string& input)
  {
    if (input.size() < 4)
    {
      return false;
    }
    if (input[0] != '-' && input[0] != '+' && !std::isdigit(static_cast<unsigned char>(input[0])))
    {
      return false;
    }
    if (input[input.size() - 1] != 'f')
    {
      return false;
    }
    std::string::size_type posDot = input.find('.');
    if (posDot == std::string::npos)
    {
      return false;
    }
    if (!isAllDigits(input, 1, posDot))
    {
      return false;
    }
    if (!isAllDigits(input, posDot + 1, input.size() - 1))
    {
      return false;
    }
    return true;
  }

  bool isDouble(const std::string& input)
  {
    if (input.size() < 3)
    {
      return false;
    }
    if (input[0] != '-' && input[0] != '+' && !std::isdigit(static_cast<unsigned char>(input[0])))
    {
      return false;
    }
    std::string::size_type posDot = input.find('.');
    if (posDot == std::string::npos)
    {
      return false;
    }
    if (!isAllDigits(input, 1, posDot))
    {
      return false;
    }
    if (!isAllDigits(input, posDot + 1, input.size()))
    {
      return false;
    }
    return true;
  }

  bool isInt(const std::string& input)
  {
    if (input[0] != '-' && input[0] != '+' && !std::isdigit(static_cast<unsigned char>(input[0])))
    {
      return false;
    }
    if (!isAllDigits(input, 1, input.size()))
    {
      return false;
    }
    return true;
  }

  void handleChar(const std::string& input, Data& data)
  {
    data.cPossible = true;
    data.fPossible = true;
    data.dPossible = true;
    data.iPossible = true;
    data.c = input[0];
    data.f = static_cast<float>(data.c);
    data.d = static_cast<double>(data.c);
    data.i = static_cast<int>(data.c);
    data.suffixFloat = ".0f";
    data.suffixDouble = ".0";
  }

  void handleFloat(const std::string& input, Data& data)
  {
    std::istringstream iss(input);
    iss >> data.f;
    if (iss.fail())
    {
      bool isNegative = input[0] == '-' ? true : false;
      data.f = isNegative ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
    }
    data.fPossible = true;

    if (data.f >= std::numeric_limits<char>::min() && data.f <= std::numeric_limits<char>::max())
    {
      data.cPossible = true;
      data.c = static_cast<char>(data.f);
    }

    if (data.f >= std::numeric_limits<int>::min() && data.f <= std::numeric_limits<int>::max())
    {
      data.iPossible = true;
      data.i = static_cast<int>(data.f);
    }
    
    data.dPossible = true;
    data.d = static_cast<double>(data.f);

    setSuffix(data);
  }

  void handleDouble(const std::string& input, Data& data)
  {
    std::istringstream iss(input);
    iss >> data.d;
    if (iss.fail())
    {
      bool isNegative = input[0] == '-' ? true : false;
      data.d = isNegative ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity();
    }
    data.dPossible = true;

    if (data.d >= std::numeric_limits<char>::min() && data.d <= std::numeric_limits<char>::max())
    {
      data.cPossible = true;
      data.c = static_cast<char>(data.d);
    }

    data.fPossible = true;
    data.f = static_cast<float>(data.d);
    
    if (data.d >= std::numeric_limits<int>::min() && data.d <= std::numeric_limits<int>::max())
    {
      data.iPossible = true;
      data.i = static_cast<int>(data.d);
    }

    setSuffix(data);
  }

  void handleInteger(const std::string& input, Data& data)
  {
    std::istringstream iss(input);
    iss >> data.i;
    if (iss.fail())
    {
      return;
    }
    data.iPossible = true;

    if (data.i >= std::numeric_limits<char>::min() && data.i <= std::numeric_limits<char>::max())
    {
      data.cPossible = true;
      data.c = static_cast<char>(data.i);
    }

    data.fPossible = true;
    data.f = static_cast<float>(data.i);
    data.suffixFloat = ".0f";

    data.dPossible = true;
    data.d = static_cast<double>(data.i);
    data.suffixDouble = ".0";
  }

  void handleSpecialValues(const std::string& input, Data& data)
  {
    if (input == "nan" || input == "nanf")
    {
      data.cPossible = false;
      data.iPossible = false;
      data.fPossible = true;
      data.dPossible = true;
      data.f = std::numeric_limits<float>::quiet_NaN();
      data.d = std::numeric_limits<double>::quiet_NaN();
    }
    if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
      data.cPossible = false;
      data.iPossible = false;
      data.fPossible = true;
      data.dPossible = true;
      data.f = std::numeric_limits<float>::infinity();
      data.d = std::numeric_limits<double>::infinity();
    }
    if (input == "-inf" || input == "-inff")
    {
      data.cPossible = false;
      data.iPossible = false;
      data.fPossible = true;
      data.dPossible = true;
      data.f = -std::numeric_limits<float>::infinity();
      data.d = -std::numeric_limits<double>::infinity();
    }
    data.suffixFloat = "f";
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

  Data data;

  if (isChar(input))
    handleChar(input, data);
  else if (isFloat(input))
    handleFloat(input, data);
  else if (isDouble(input))
    handleDouble(input, data);
  else if (isInt(input))
    handleInteger(input, data);
  else
    handleSpecialValues(input, data);

  print(data);

  return 0;
}
