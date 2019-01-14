#ifndef BOXSTRUCT_H
#define BOXSTRUCT_H

struct box {
  static const int rowSize = 5 /*rows*/;
  static const int charsSize = (9 /*characters*/ * 4 /*bytes*/);
  char content[rowSize][charsSize];
};

#endif /* BOXSTRUCT_H */
