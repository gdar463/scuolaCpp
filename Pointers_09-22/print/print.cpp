#include <iostream>

// Per gestire meglio i progetti uso CMake e un'unico main file
// per i vari main li divido attraverso namespace
#ifdef USING_CMAKE
namespace Print {
#endif

void printArray(int *array, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "Elemento n° " << i << ": " << *(array + i) << std::endl;
  }
}

int main() {
  int myArray[5]{1, 2, 3, 4, 5};
  // Possiamo passare direttamente `myArray` alla funzione
  // perché `myArray` in realtà è un puntatore che punta
  // al primo elemento dell'array
  printArray(myArray, 5);
  return 0;
}

#ifdef USING_CMAKE
}
#endif
