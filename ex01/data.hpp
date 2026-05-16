#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
  const char c;
  const int i;
  const float f;
  const double d;
  Data() : c('a'), i(97), f(97.0f), d(97.0) {}
};

#endif