#ifndef ZOBRISTKEY_H
#define ZOBRISTKEY_H
#include <random>
#include "../defs.h"

class Board;

using std::random_device;
using std::mt19937_64;
using std::uniform_int_distribution;

class ZobristKey {
 public:
  ZobristKey();
  ZobristKey(Board*, bool black_to_move);
  virtual ~ZobristKey();
  static void _init();
  U64 get_zobrist_key() const;
  void XOR_piece(int piece, unsigned int index);
  void move_piece(int piece, unsigned int from , unsigned int to);
  void capture_piece(int capture, unsigned int to);
  void undo_move(int piece, int capture, unsigned int from, unsigned int to);
  bool operator==(const ZobristKey&);
  void change_turn();

  private:
  U64 m_key = BLANK;
  static U64 m_piece_keys[13][64];
  static U64 BLACK_TO_MOVE_KEY;
};

#endif /* ZOBRISTKEY_H */
