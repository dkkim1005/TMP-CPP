#include <iostream>
#define idtype(T) idType<T>()

template<class T1, class T2>
struct typeCheck {
  static const bool value = false;
};

template<class T>
struct typeCheck<T,T> {
  static const bool value = true;
};

template<class T>
struct idType
{
  template<class T2>
  bool operator==(const idType<T2>& rhs) {
    return typeCheck<T,T2>::value;
  }
};

int main(int argc, char* argv[])
{
  std::cout << typeCheck<float, float>::value << std::endl;
  std::cout << (idtype(kaka) == idtype(kaka)) << std::endl;
  return 0;
}
