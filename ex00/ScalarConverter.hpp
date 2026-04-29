
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
  public:
    static void convert(std::string input);
  private:
    ScalarConverter(); // declared private, and not implemented - this makes it impossible to instantiate the class
};

#endif