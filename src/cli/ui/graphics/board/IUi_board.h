#ifndef UI_BOARD_H
#define UI_BOARD_H

class IUIBoard {
 public:
  virtual void print() = 0;
  virtual void update() = 0;
};

#endif /* UI_BOARD_H */
