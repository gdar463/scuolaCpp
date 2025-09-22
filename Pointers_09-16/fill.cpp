#include <algorithm>
#include <cstddef>

double fill_and_avg(std::size_t n, double val) {
  if (n == 0)
    return 0.0;

  double *arr{new double[n]};
  std::fill(arr, arr + n, val);
  double avg{0.0};

  for (double *i = arr; i < arr + n; ++i) {
    avg += *i;
  }
  avg = avg / n;

  delete[] arr;
  return avg;
}
