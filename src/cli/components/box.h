#ifndef BOX_H
#define BOX_H

#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include <string>

#define snprintf_nowarn(...) (snprintf(__VA_ARGS__) < 0 ? abort() : (void) 0)

class Box {
 public:
  Box() {}
  Box(std::initializer_list<const char *> lst) {
    int counter = 0;
    for (const auto l : lst) copy_row(content[counter++], l);
  }

  static void copy_row(char *dest, const char *src) {
    snprintf(dest, kCharSize, "%s", src);
  }

  static void copy_row(char *dest, const char *src, const char *src2) {
    snprintf_nowarn(dest, kCharSize, "%s%s", src, src2);
  }

  static const int kRowSize = 5 /*rows*/;

  // drawing   7 chars "█████████"
  // color fg  3 chars "\033[38;5;m"
  // color bg  4 chars "\x1B[48;5;m"
  // attr      3 chars "\033[7m"
  // reset     3 chars "\033[0m"
  // 68 bytes aprox
  static const int kCharSize = (17 /*characters*/ * 4 /*bytes*/);
  char content[kRowSize][kCharSize];
};

#endif /* BOX_H */
