#include "clamp.hpp"
#include "fill.hpp"
#include "swap.hpp"
// #include <cstddef>
#include <iostream>

int main() {
  // D1: Swap without Temp
  // int *a{new int(10)};
  // int *b{new int(30)};
  // swap_no_temp(a, b);
  //
  // D2: Fill and Avg without [] operator
  // std::size_t n{10};
  // double val{5.0};
  // std::cout << fill_and_avg(n, val) << std::endl;
  //
  // E: Clamp in place
  int *val{new int(100)};
  int low{1};
  int high{10};
  clamp(val, low, high);
  std::cout << *val << std::endl;

  return 0;
}
