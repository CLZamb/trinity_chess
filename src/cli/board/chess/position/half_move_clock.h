#ifndef HALF_MOVE_CLOCK_H
#define HALF_MOVE_CLOCK_H

#include "utils/move.hpp"
class HalfMoveClock {
 public:
  HalfMoveClock();
  virtual ~HalfMoveClock();

  void update_halfmoves(const Move &m);
  void update_fullmoves();

  void set_halfmoves(int half_moves);
  void set_fullmoves(int half_moves);

  std::string get_halfmoves_as_string();
  std::string get_fullmoves_as_string();

  void clear();

 private:
  int m_halfmoves{0};
  int m_fullmoves{1};
};

#endif /* HALF_MOVE_CLOCK_H */
