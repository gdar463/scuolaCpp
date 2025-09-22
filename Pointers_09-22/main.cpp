#include "fill/fill.cpp"
#include "print/print.cpp"
#include "swap/swap.cpp"
#include <iostream>

int main() {
  std::cout << "Fill Main" << "\n\n";
  Fill::main();
  std::cout << "\nSwap Main" << "\n\n";
  Swap::main();
  std::cout << "\nPrint Main" << "\n\n";
  Print::main();
}
