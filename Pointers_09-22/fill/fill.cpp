#include <iostream>

// Per gestire meglio i progetti uso CMake e un'unico main file
// per i vari main li divido attraverso namespace
#ifdef USING_CMAKE
namespace Fill {
#endif

int *createAndFillArray(int size) {
  int *array{new int[size]};
  for (int i = 0; i < size; i++) {
    array[i] = i;
  }
  return array;
}

int main() {
  int size;
  std::cout << "Inserisci la dimensione dell'array: ";
  std::cin >> size;
  int *array{createAndFillArray(size)};
  for (int i = 0; i < size; i++) {
    std::cout << "Elemento n° " << i << ": " << array[i] << std::endl;
  }
  delete[] array;
  return 0;
}

#ifdef USING_CMAKE
}
#endif
