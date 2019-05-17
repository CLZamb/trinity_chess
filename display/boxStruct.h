#ifndef BOXSTRUCT_H
#define BOXSTRUCT_H

struct box {
  static const int kRowSize = 5 /*rows*/;
  static const int kCharSize = (9 /*characters*/ * 5 /*bytes*/);
  char content[kRowSize][kCharSize];
};

#endif /* BOXSTRUCT_H */
