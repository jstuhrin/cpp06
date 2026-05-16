
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
  public:
    static int convert(std::string input);
  private:
    ScalarConverter(); // declared private, and not implemented - this makes it impossible to instantiate the class
};

#endif
