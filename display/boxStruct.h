#ifndef BOXSTRUCT_H
#define BOXSTRUCT_H

struct box {
  static const int row_size = 5 /*rows*/;
  static const int char_size = (9 /*characters*/ * 5 /*bytes*/);
  char content[row_size][char_size];
};

#endif /* BOXSTRUCT_H */
