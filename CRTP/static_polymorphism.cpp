#include <iostream>

template<class T>
struct base
{
  void interface() {
    static_cast<T*>(this) -> implementation();
  }
};

struct derived : public base<derived>
{
  void implementation() const {
    std::cout << "hello world" << std::endl;
  }
};

template<class T>
void check_hello(base<T>& tester) {
  tester.interface();
}

int main(int argc, char* argv[])
{
  derived x;
  check_hello(x);
  return 0;
}
