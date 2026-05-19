#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
  char c;
  int i;
  float f;
  double d;
  Data() : c('a'), i(97), f(97.0f), d(97.0) {}
};

#endif