#include <iostream>

// Per gestire meglio i progetti uso CMake e un'unico main file
// per i vari main li divido attraverso namespace
#ifdef USING_CMAKE
namespace Swap {
#endif

void swapValues(int *ptr1, int *ptr2) {
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

int main() {
  int a{5}, b{10};
  int *ptrA{&a}, *ptrB{&b};

  std::cout << "Prima dello swap" << std::endl;
  std::cout << "A: " << a << std::endl;
  std::cout << "B: " << b << std::endl;

  swapValues(ptrA, ptrB);

  std::cout << "Dopo lo swap" << std::endl;
  std::cout << "A: " << a << std::endl;
  std::cout << "B: " << b << std::endl;

  return 0;
}

#ifdef USING_CMAKE
}
#endif
