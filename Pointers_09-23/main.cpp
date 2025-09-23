#include <cstddef>

size_t cstr_len(const char *s) { return 0; };

bool cstr_copy(char *dst, size_t cap, const char *src) { return true; };

bool cstr_cat(char *dst, size_t cap, const char *src) { return true; }

int cstr_cmp(const char *a, const char *b) { return 0; };

void cstr_remove_char(char *s, char ch) {};

int main() { return 0; }
