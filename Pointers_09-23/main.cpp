#include <cstddef>
#include <iostream>

size_t cstr_len(const char *s) {
  if (s == nullptr)
    return 0;
  size_t out{0};
  while (*s != '\x0') {
    out++;
    ++s;
  }
  return out;
}

bool cstr_copy(char *dst, size_t cap, const char *src) {
  if (dst == nullptr || src == nullptr)
    return false;

  size_t len{cstr_len(src)};
  if (len > cap)
    return false;

  for (int i = 0; i < len; i++) {
    *(dst + i) = *(src + i);
  }

  return true;
}

bool cstr_cat(char *dst, size_t cap, const char *src) {
  if (dst == nullptr || src == nullptr)
    return false;

  size_t src_len{cstr_len(src)};
  size_t dst_len{cstr_len(dst)};
  size_t len{src_len + dst_len};
  if (len + 1 > cap) // fix dopo visto soluzioni
    return false;

  for (int i = dst_len; i < len; i++) {
    *(dst + i) = *(src + i - dst_len);
  }

  return true;
}

int cstr_cmp(const char *a, const char *b) {
  if (a == nullptr || b == nullptr)
    return 0;

  int i{0};
  for (; *(a + i) != '\x0'; i++) {
    if (*b == '\x0')
      return -1;
    if (*(a + i) != *(b + i))
      return *(a + i) > *(b + i) ? 1 : -1;
  }
  int size_b = cstr_len(b);
  if (size_b > i) {
    return -1;
  }
  return 0;
}

// Versione precedente usava find per cercare il carattere
void cstr_remove_char(char *s, char ch) {
  if (s == nullptr)
    return;

  size_t len{cstr_len(s)};
  char *c{s};

  while (*c != '\x0') {
    if (*c == ch) {
      for (char *d = c; d != s + len; ++d) {
        *d = *(d + 1);
      }
    } else {
      ++c;
    }
  }
}

int main() {
  const char len_s[]{"stuff"};

  std::cout << "cstr_len(s)" << std::endl;
  std::cout << "s: " << len_s << std::endl;
  std::cout << "out: " << cstr_len(len_s) << "\n\n";

  size_t copy_cap = 10;
  char *copy_dst{new char[copy_cap]};
  const char copy_src[]{"source"};

  std::cout << "cstr_copy(dst, cap, src)" << std::endl;
  std::cout << "dst: " << copy_dst << std::endl;
  std::cout << "cap: " << copy_cap << std::endl;
  std::cout << "src: " << copy_src << std::endl;
  std::cout << "out: "
            << (cstr_copy(copy_dst, copy_cap, copy_src) ? "true" : "false")
            << std::endl;
  std::cout << "dst: " << copy_dst << "\n\n";

  size_t cat_cap = 25;
  char *cat_dst{new char[cat_cap]{"dst"}};
  const char cat_src[]{"source"};

  std::cout << "cstr_cat(dst, cap, src)" << std::endl;
  std::cout << "dst: " << cat_dst << std::endl;
  std::cout << "cap: " << cat_cap << std::endl;
  std::cout << "src: " << cat_src << std::endl;
  std::cout << "out: "
            << (cstr_cat(cat_dst, cat_cap, cat_src) ? "true" : "false")
            << std::endl;
  std::cout << "dst: " << cat_dst << "\n\n";

  const char a[]{"orange"};
  const char b[]{"apple"};

  std::cout << "cstr_cmp(a, b)" << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "out: " << cstr_cmp(a, b) << "\n\n";

  char *rm_s{new char[]{"sasso rosso"}};
  const char ch{'s'};

  std::cout << "cstr_remove_char(s, ch)" << std::endl;
  std::cout << "s: " << rm_s << std::endl;
  std::cout << "ch: " << ch << std::endl;
  cstr_remove_char(rm_s, ch);
  std::cout << "out: <void>" << std::endl;
  std::cout << "s: " << rm_s << std::endl;
}
