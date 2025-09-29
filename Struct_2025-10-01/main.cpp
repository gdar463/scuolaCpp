#include <cstddef>
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
  Student(char *_name, int *_marks, size_t _n) {
    if (*_name == '\x0') {
      name = new char[]{""};
    } else {
      name = new char[cstr_len(_name)];
      cstr_copy(_name, name);
    }

    if (_marks == nullptr || _n == 0) {
      marks = nullptr;
      n = 0;
    } else {
      marks = new int[_n];
      n = _n;
      for (int i = 0; i < _n; i++) {
        if (_marks[i] < 3 || _marks[i] > 10) {
          n--;
          continue;
        }
        marks[i] = _marks[i];
      }
    }
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

void testNewStudent(Student *s) {
  std::srand(time(NULL));

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
}

int main() {
  char name_alice[] = "Alice";
  const size_t n_alice = 4;
  int marks_alice[n_alice] = {10, 6, 7, 14};
  Student *s_alice = new Student(name_alice, marks_alice, n_alice);
  std::cout << "Alice" << std::endl;
  testNewStudent(s_alice);

  char name_bob[] = "Bob";
  Student *s_bob = new Student(name_bob);
  std::cout << "\nBob" << std::endl;
  testNewStudent(s_bob);
  return 0;
}
