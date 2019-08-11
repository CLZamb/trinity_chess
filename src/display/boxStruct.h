#ifndef BOXSTRUCT_H
#define BOXSTRUCT_H
#include <initializer_list>
#include <iostream>
#include <algorithm>

class box {
  public:
  box() {}
  box(std::initializer_list<const char*> lst) {
    int counter = 0;
    for (const auto l : lst)
      copy_row(content[counter++], l);
  }

  static void copy_row(char* dest, const char* src) {
    snprintf(dest, kCharSize, "%s", src);
  }

  static void copy_row(char* dest, const char* src, const char* src2) {
    snprintf(dest, kCharSize, "%s%s", src, src2);
  }

  static const int kRowSize = 5 /*rows*/;
  static const int kCharSize = (9 /*characters*/ * 5 /*bytes*/);
  char content[kRowSize][kCharSize];
};

#endif /* BOXSTRUCT_H */
