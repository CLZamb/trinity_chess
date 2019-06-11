#include "ZobristKey.h"
#include "board.h"

U64 ZobristKey::m_piece_keys[13][64];
U64 ZobristKey::BLACK_TO_MOVE_KEY;

/*Must be initialize before use the Zobrist keys*/
void ZobristKey::_init() {
  /* Initialise. Do this once (not for every
     random number). */
  random_device rd;
  mt19937_64 gen(rd());

  /* This is where you define the number generator for unsigned long long: */
  uniform_int_distribution<U64> dis;
  BLACK_TO_MOVE_KEY = dis(gen);
  for (int pce = bP; pce <= wK; ++pce)
    for (int SqIndex = Squarebegin; SqIndex < SquareEnd; ++SqIndex)
      m_piece_keys[pce][SqIndex] = dis(gen);
}

ZobristKey::ZobristKey() {}
ZobristKey::ZobristKey(Board* board, bool black_to_move) {
  if (black_to_move)
    m_key ^= BLACK_TO_MOVE_KEY;

  U64 square = BLANK;
  U64 piece_bitboard = BLANK;
  for (int pce = bP; pce <= wK; ++pce) {
    piece_bitboard = board->get_piece_bitboard(pce);
    for (int SqIndex = Squarebegin; SqIndex < SquareEnd; ++SqIndex) {
      square = ONE << SqIndex;
      if (square & piece_bitboard)
        XOR_piece(pce, SqIndex);
    }
  }
}

ZobristKey::~ZobristKey() {}

void ZobristKey::XOR_piece(int piece, unsigned int index) {
  m_key ^= m_piece_keys[piece][index];
}

void ZobristKey::move_piece(int piece, unsigned int from, unsigned int to) {
  XOR_piece(piece, from);
  XOR_piece(piece, to);
}

void ZobristKey::capture_piece(int piece, unsigned int pos) {
  XOR_piece(piece, pos);
}

void ZobristKey::undo_move(
    int piece, int captured, unsigned int from, unsigned int to) {
  XOR_piece(piece, from);
  XOR_piece(piece, to);
  XOR_piece(captured, from);
}

bool ZobristKey::operator==(const ZobristKey& other) {
  return m_key == other.get_zobrist_key();
}

U64 ZobristKey::get_zobrist_key() const {
  return m_key;
}

void ZobristKey::change_turn() {
  m_key ^= BLACK_TO_MOVE_KEY;
}
