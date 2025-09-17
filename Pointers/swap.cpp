#include <stdexcept>

void swap_no_temp(int *a, int *b) {
  if (a == nullptr || b == nullptr) {
    throw std::invalid_argument("one of the pointers is null");
  }

  if (a == b || *a == *b)
    return;

  // Trovato online, purtroppo :(
  //
  // Eseguendo XORs su uno dei due dati puntati
  // si può "salvare" un fantasma dell'altro
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}
