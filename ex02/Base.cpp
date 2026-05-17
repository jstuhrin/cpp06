
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate()
{
  std::srand(std::time(NULL));
  const int random = std::rand() % 3;

  switch (random)
  {
    case 0:
      return new A;
    case 1:
      return new B;
    case 2:
      return new C;
  }
  assert(false && "Mmh - I guess the modulo operation is broken?!");
  __builtin_unreachable();
}

void identify(Base* p)
{
  A* a = dynamic_cast<A*>(p);
  if (a != NULL)
  {
    std::cout << "Congrats! It's an A!\n";
  }

  B* b = dynamic_cast<B*>(p);
  if (b != NULL)
  {
    std::cout << "Congrats! It's a B!\n";
  }
  
  C* c = dynamic_cast<C*>(p);
  if (c != NULL)
  {
    std::cout << "Congrats! It's a C!\n";
  }
}

void identify(Base& p)
{
  try
  {
    A& a = dynamic_cast<A&>(p);
    std::cout << "Congrats! It's an A!\n";
    assert(&a == &p);
  }
  catch (const std::exception& e)
  {

  }

  try
  {
    B& b = dynamic_cast<B&>(p);
    std::cout << "Congrats! It's a B!\n";
    assert(&b == &p);
  }
  catch (const std::exception& e)
  {

  }

  try
  {
    C& c = dynamic_cast<C&>(p);
    std::cout << "Congrats! It's a C!\n";
    assert(&c == &p);
  }
  catch (const std::exception& e)
  {

  }
}