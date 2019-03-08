#ifndef SQUARE_H
#define SQUARE_H
#include "boxStruct.h"

class Square
{
 private:
   box* p_cur_square_drawing;

 public:
   Square();
   virtual ~Square();
   box* get_square_drawing();
};

#endif /* SQUARE_H */
