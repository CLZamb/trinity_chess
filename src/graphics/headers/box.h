#ifndef BOXSTRUCT_H
#define BOXSTRUCT_H
#include <initializer_list>
#include <iostream>

#define snprintf_nowarn(...) (snprintf(__VA_ARGS__) < 0 ? abort() : (void)0)

class Box {
  public:
    Box() {}
    Box(std::initializer_list<const char*> lst) {
      int counter = 0;
      for (const auto l : lst)
        copy_row(content[counter++], l);
    }

    static void copy_row(char* dest, const char* src) {
      snprintf(dest, kCharSize, "%s", src);
    }

    static void copy_row(char* dest, const char* src, const char* src2) {
      snprintf_nowarn(dest, kCharSize, "%s%s", src, src2);
    }

    static const int kRowSize = 5 /*rows*/;
    static const int kCharSize = (15/*characters*/ * 4 /*bytes*/);
    char content[kRowSize][kCharSize];
};

#endif /* BOXSTRUCT_H */
