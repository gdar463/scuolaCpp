void clamp(int *value, int low, int high) {
  if (value == nullptr) {
    return;
  } else if (*value > high) {
    *value = high;
  } else if (*value < low) {
    *value = low;
  }
};
