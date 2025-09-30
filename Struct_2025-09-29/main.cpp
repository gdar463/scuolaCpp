#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace Config {

static const size_t UNIT_MARKS_N = 10; // usata sia per inizializzare marks che
                                       // per aumento size a momento di realloc
static const int MIN_MARK = 3;
static const int MAX_MARK = 10;

} // namespace Config

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
      marks = new int[Config::UNIT_MARKS_N];
      n = Config::UNIT_MARKS_N;
      for (int i = 0; i < n; i++) {
        marks[i] = 0;
      }
    } else {
      n = _n > Config::UNIT_MARKS_N ? _n : Config::UNIT_MARKS_N;
      marks = new int[n];
      for (int i = 0; i < _n; i++) {
        if (_marks[i] < Config::MIN_MARK || _marks[i] > Config::MAX_MARK) {
          n--;
          continue;
        }
        marks[i] = _marks[i];
      }
    }
  }
};

bool addMark(Student *s, int mark) {
  if (mark < Config::MIN_MARK || mark > Config::MAX_MARK)
    return false;
  if (s == nullptr)
    return false;

  int *val = s->marks;
  while (true) {
    if (val == s->marks + s->n) {
      int *temp = new int[s->n + Config::UNIT_MARKS_N];
      for (int i = 0; i < s->n; i++) {
        temp[i] = s->marks[i];
      }
      temp[s->n] = mark;
      delete[] s->marks;
      s->marks = temp;
      s->n += Config::UNIT_MARKS_N;
      return true;
    }

    if (*val == 0) {
      *val = mark;
      return true;
    }

    ++val;
  }
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
    if (s->marks[i] == 0)
      return out / i;
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
  for (int i = 0; i < 15; i++) {
    int mark = rand() % 15; // modulo 15 per testare anche oltre al 10
    addMark(s, mark);
  }

  print(s);
  deleteStudent(s);
  return 0;
}
