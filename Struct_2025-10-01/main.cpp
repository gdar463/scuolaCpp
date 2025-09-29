#include <cstdlib>
#include <ctime>
#include <iostream>

int cstr_len(char *str) {
  char *p = str;
  while (true) {
    if (*p == '\x0')
      return p - str;
    ++p;
  }
}

void cstr_copy(char *src, char *dst) {
  while (true) {
    *dst = *src;
    if (*dst == '\x0')
      break;
    ++dst, ++src;
  }
}

struct Student {
  char *name;
  int *marks;
  size_t n;
  Student(char *_name) {
    if (*_name == '\x0') {
      name = new char[]{""};
    } else {
      name = new char[cstr_len(_name)];
      cstr_copy(_name, name);
    }
    marks = nullptr;
    n = 0;
  }
};

bool addMark(Student *s, int mark) {
  if (mark < 3 || mark > 10)
    return false;
  if (s == nullptr)
    return false;

  if (s->marks == nullptr) {
    s->marks = new int[1]{mark};
    s->n++;
    return true;
  }

  int *temp = new int[s->n + 1];
  for (int i = 0; i < s->n; i++) {
    temp[i] = s->marks[i];
  }
  temp[s->n] = mark;
  s->marks = temp;
  s->n++;
  return true;
}

double calcMedia(Student *s) {
  if (s == nullptr)
    return 0;
  if (s->marks == nullptr)
    return 0;
  if (s->n == 0)
    return 0;

  double out = 0;
  for (int i = 0; i < s->n; i++) {
    out += s->marks[i];
  }
  return out / s->n;
}

// Name: V1 V2 .., Media:
void print(Student *s) {
  if (s == nullptr)
    return;

  std::cout << s->name;
  if (s->n != 0) {
    std::cout << ": ";
    for (int i = 0; i < s->n; i++) {
      std::cout << s->marks[i];
      if (i != s->n - 1)
        std::cout << " ";
    }
    std::cout << ", Media: " << calcMedia(s);
  }
  std::cout << std::endl;
}

void deleteStudent(Student *s) {
  delete s->name;
  delete s->marks;
  delete s;
}

int main() {
  std::srand(time(NULL));
  char name[] = "Josh";
  Student *s = new Student(name);

  std::cout << "name: " << s->name << "\n\n";

  for (int i = 0; i < 10; i++) {
    int mark = rand() % 15;
    std::cout << "mark: " << mark
              << " result: " << (addMark(s, mark) ? "true" : "false")
              << std::endl;
  }

  std::cout << "\nn: " << s->n << "\n\n";
  for (int i = 0; i < s->n; i++) {
    std::cout << "i: " << i << " mark: " << s->marks[i] << std::endl;
  }
  std::cout << std::endl;

  print(s);
  deleteStudent(s);
  return 0;
}
