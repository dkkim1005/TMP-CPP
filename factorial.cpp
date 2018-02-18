#include <iostream>
#define factorial(N) factorialClass<N>::value

template<unsigned int N>
struct factorialClass {
  static const unsigned int value = N*factorialClass<N-1>::value;
};

template<>
struct factorialClass<0> {
  static const unsigned int value = 1;
};

int main(int argc, char* argv[])
{
  std::cout << factorial(5) << std::endl;
  return 0;
}
