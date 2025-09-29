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

  Student(char *_name, int *_marks = nullptr, size_t _n = 0) {
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
  if (s->marks == nullptr || s->n == 0) {
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

double avgMarks(Student *s) {
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

void print(Student *s) {
  if (s == nullptr)
    return;

  std::cout << s->name;
  if (s->n != 0) {
    std::cout << ": ";
    for (int i = 0; i < s->n; i++) {
      std::cout << s->marks[i] << " ";
    }
    std::cout << "| media = " << avgMarks(s);
  }
  std::cout << std::endl;
}

void deleteStudent(Student *s) {
  delete[] s->name;
  delete[] s->marks;
  s->name = nullptr;
  s->marks = nullptr;
  s->n = 0;
}

int main() {
  char name[] = "Alice";
  const size_t n = 4;
  int marks[n] = {10, 6, 7, 14}; // aggiunto 14 per testare il check del fuori
                                 // intervallo nel costruttore
  Student *s = new Student(name, marks, n);

  std::srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    int mark = rand() % 15; // modulo 15 per testare anche oltre al 10
    addMark(s, mark);
  }

  print(s);
  deleteStudent(s);
  return 0;
}
