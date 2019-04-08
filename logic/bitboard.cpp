#include "bitboard.h"
Bitboard::Bitboard() {
  _init_pieces();
}
Bitboard::~Bitboard() {}

void Bitboard::_init() {
  int Rook = 1, Bishop = 0;
  _init_MvvLva();
  _init_bitmasks();
  _init_nonsliders_attacks();
  _init_slider_masks_shifs_occupancies(Bishop);
  _init_slider_masks_shifs_occupancies(Rook);
  _init_tables(Bishop);
  _init_tables(Rook);
  _init_pieces_table_values();
}

void Bitboard::_init_pieces() {
  m_pieces[EMPTY] = nullptr;
  m_pieces[bP] = &m_b_pawn;
  m_pieces[bR] = &m_b_rook;
  m_pieces[bN] = &m_b_knigth;
  m_pieces[bB] = &m_b_bishop;
  m_pieces[bQ] = &m_b_queen;
  m_pieces[bK] = &m_b_king;
  m_pieces[wP] = &m_w_pawn;
  m_pieces[wR] = &m_w_rook;
  m_pieces[wN] = &m_w_knigth;
  m_pieces[wB] = &m_w_bishop;
  m_pieces[wQ] = &m_w_queen;
  m_pieces[wK] = &m_w_king;
}

void Bitboard::_init_pieces_table_values() {
  for (int i = 0; i < 64; ++i) {
    pieces_score[wP][i] = -PawnTable[i];
    pieces_score[wR][i] = -RookTable[i];
    pieces_score[wN][i] = -KnightTable[i];
    pieces_score[wB][i] = -BishopTable[i];
    pieces_score[wQ][i] = -QueenTable[i];

    pieces_score[bP][i] = PawnTable[MIRROR64[i]];
    pieces_score[bR][i] = RookTable[MIRROR64[i]];
    pieces_score[bN][i] = KnightTable[MIRROR64[i]];
    pieces_score[bB][i] = BishopTable[MIRROR64[i]];
    pieces_score[bQ][i] = QueenTable[MIRROR64[i]];
  }
}

void Bitboard::_init_MvvLva() {
  int Attacker;
  int Victim;
  for (Attacker = bP; Attacker <= wK; ++Attacker) {
    for (Victim = bP; Victim <= wK; ++Victim) {
      MvvLvaScores[Victim][Attacker] =
        VictimScore[Victim] + 6 - (VictimScore[Attacker] / 10);
    }
  }
}

Piece* Bitboard::get_piece(int type) {
  return m_pieces[type];
}

void Bitboard::_init_nonsliders_attacks() {
  int sq;

  for (sq = 0; sq < 64; sq++) {
    m_w_pawn_attacks[sq] = pawn_mask(sq, WHITE);
    m_b_pawn_attacks[sq] = pawn_mask(sq, BLACK);
    m_knight_attacks[sq] = knight_mask(sq);
    m_king_attacks[sq] = king_mask(sq);
    m_w_pawn_non_attacks[sq] = pawn_non_attack(sq, WHITE);
    m_b_pawn_non_attacks[sq] = pawn_non_attack(sq, BLACK);
  }
}

void Bitboard::_init_bitmasks() {
  for (int i = 0; i < 64; ++i) {
    SetMask[i] = 0ULL;
    ClearMask[i] = 0ULL;
  }

  for (int i = 0; i < 64; ++i) {
    SetMask[i] |= (1ULL << i);
    ClearMask[i] = ~SetMask[i];
  }

  for (int sq = 0; sq < 64; ++sq) {
    m_rook_tbl[sq].magic = RookMagic[sq];
    m_bishop_tbl[sq].magic = BishopMagic[sq];
  }
}

int Bitboard::count_1s(U64 b) {
  int r;
  for (r = 0; b; r++, b &= b - 1) {}
  return r;
}

int Bitboard::pop_1st_bit(U64* bb) {
  U64 b = *bb ^ (*bb - 1);
  unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
  *bb &= (*bb - 1);
  return BitTable[(fold * 0x783a9b23) >> 26];
}

U64 Bitboard::rmask(int sq) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
  for (r = rk+1; r <= 6; r++) result |= (1ULL << (fl + r*8));
  for (r = rk-1; r >= 1; r--) result |= (1ULL << (fl + r*8));
  for (f = fl+1; f <= 6; f++) result |= (1ULL << (f + rk*8));
  for (f = fl-1; f >= 1; f--) result |= (1ULL << (f + rk*8));
  return result;
}

U64 Bitboard::bmask(int sq) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
  for (r = rk+1, f=fl+1; r <= 6 && f <= 6; r++, f++)
    result |= (1ULL << (f + r*8));
  for (r = rk+1, f=fl-1; r <= 6 && f >= 1; r++, f--)
    result |= (1ULL << (f + r*8));
  for (r = rk-1, f=fl+1; r >= 1 && f <= 6; r--, f++)
    result |= (1ULL << (f + r*8));
  for (r = rk-1, f=fl-1; r >= 1 && f >= 1; r--, f--)
    result |= (1ULL << (f + r*8));
  return result;
}

U64 Bitboard::ratt(int sq, U64 block) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
  for (r = rk+1; r <= 7; r++) {
    result |= (1ULL << (fl + r*8));
    if (block & (1ULL << (fl + r*8))) break;
  }
  for (r = rk-1; r >= 0; r--) {
    result |= (1ULL << (fl + r*8));
    if (block & (1ULL << (fl + r*8))) break;
  }
  for (f = fl+1; f <= 7; f++) {
    result |= (1ULL << (f + rk*8));
    if (block & (1ULL << (f + rk*8))) break;
  }
  for (f = fl-1; f >= 0; f--) {
    result |= (1ULL << (f + rk*8));
    if (block & (1ULL << (f + rk*8))) break;
  }
  return result;
}

U64 Bitboard::batt(int sq, U64 block) {
  U64 result = 0ULL;
  int rk = sq/8, fl = sq%8, r, f;
  for (r = rk+1, f = fl+1; r <= 7 && f <= 7; r++, f++) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  for (r = rk+1, f = fl-1; r <= 7 && f >= 0; r++, f--) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  for (r = rk-1, f = fl+1; r >= 0 && f <= 7; r--, f++) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  for (r = rk-1, f = fl-1; r >= 0 && f >= 0; r--, f--) {
    result |= (1ULL << (f + r*8));
    if (block & (1ULL << (f + r * 8))) break;
  }
  return result;
}

U64 Bitboard::bishop_attacks(U64 occ, SquareIndices sq) {
  // U64* aptr = m_bishop_tbl[sq].ptr;
  occ &= m_bishop_tbl[sq].mask;
  occ *= m_bishop_tbl[sq].magic;
  occ >>=  m_bishop_tbl[sq].shift;
  return m_bishop_table[sq][occ];
}

U64 Bitboard::rook_attacks(U64 occ, SquareIndices sq) {
  // U64* aptr = m_rook_tbl[sq].ptr;
  occ &= m_rook_tbl[sq].mask;
  occ *=  m_rook_tbl[sq].magic;
  occ >>= m_rook_tbl[sq].shift;
  return m_rook_table[sq][occ];
}

U64 Bitboard::queen_attacks(U64 occ, SquareIndices sq) {
  U64 result = 0ULL;
  U64 temp_occ = occ;

  occ &= m_bishop_tbl[sq].mask;
  occ *= m_bishop_tbl[sq].magic;
  occ >>=  m_bishop_tbl[sq].shift;

  result = m_bishop_table[sq][occ];

  temp_occ &= m_rook_tbl[sq].mask;
  temp_occ *= m_rook_tbl[sq].magic;
  temp_occ >>= m_rook_tbl[sq].shift;

  result |= m_rook_table[sq][temp_occ];

  return result;
}

U64 Bitboard::pawn_non_attack(int sq, int side) {
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (side == WHITE) {
    if (fromSq << 8)
      result |= fromSq << 8;

    if ((fromSq & ROWMASK[1]) << 16)
      result |= fromSq  << 16;
  } else {
    if (fromSq >> 8)
      result |= fromSq >> 8;

    if ((fromSq & ROWMASK[6]) >> 16)
      result |= fromSq >> 16;
  }

  return result;
}

U64 Bitboard::pawn_mask(int sq, int side) {
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (side == WHITE) {
    if (fromSq << 7 & NOT_H_FILE)
      result |= fromSq << 7;

    if (fromSq << 9 & NOT_A_FILE)
      result |= fromSq << 9;
  } else {
    if (fromSq >> 7 & NOT_A_FILE)
      result |= fromSq >> 7;

    if (fromSq >> 9 & NOT_H_FILE)
      result |= fromSq >> 9;
  }

  return result;
}

U64 Bitboard::king_mask(int sq) {
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (fromSq >> 1 & NOT_H_FILE)
    result |= fromSq >> 1 & NOT_H_FILE;

  if (fromSq << 1 & NOT_A_FILE)
    result |= fromSq << 1 & NOT_A_FILE;

  if (fromSq >> 7 & NOT_A_FILE)
    result |= fromSq >> 7 & NOT_A_FILE;

  if (fromSq << 7 & NOT_H_FILE)
    result |= fromSq << 7 & NOT_H_FILE;

  if (fromSq >> 8)
    result |= fromSq >> 8;

  if (fromSq << 8)
    result |= fromSq << 8;

  if (fromSq >> 9 & NOT_H_FILE)
    result |= fromSq >> 9 & NOT_H_FILE;

  if (fromSq << 9 & NOT_A_FILE)
    result |= fromSq << 9 & NOT_A_FILE;

  return result;
}

U64 Bitboard::knight_mask(int sq) {
  U64 result = 0ULL;
  U64 fromSq = ONE << sq;

  if (fromSq >> 17 & NOT_H_FILE)
    result |= fromSq >> 17 & NOT_H_FILE;

  if (fromSq >> 15 & NOT_A_FILE)
    result |= fromSq >> 15 & NOT_A_FILE;

  if (fromSq >> 10 & NOT_GH_FILE)
    result |= fromSq >> 10 & NOT_GH_FILE;

  if (fromSq >> 6 & NOT_AB_FILE)
    result |= fromSq >> 6 & NOT_AB_FILE;

  if (fromSq << 17 & NOT_A_FILE)
    result |= fromSq << 17 & NOT_A_FILE;

  if (fromSq << 15 & NOT_H_FILE)
    result |= fromSq << 15 & NOT_H_FILE;

  if (fromSq << 10 & NOT_AB_FILE)
    result |= fromSq << 10 & NOT_AB_FILE;

  if (fromSq << 6 & NOT_GH_FILE)
    result |= fromSq << 6 & NOT_GH_FILE;

  return result;
}

U64 Bitboard::set_occupancy(int index, int bits, U64 m) {
  int i, j;
  U64 result = 0ULL;

  for (i = 0; i < bits; i++) {
    j = pop_1st_bit(&m);
    if (index & (1 << i))
      result |= (1ULL << j);
  }

  return result;
}

void Bitboard::_init_slider_masks_shifs_occupancies(int isRook) {
  int i, bitCount, variationCount;
  U64 mask;

  for (int bitRef = A1; bitRef < Squareend; ++bitRef) {
    m_rook_tbl[bitRef].mask = rmask(bitRef);
    m_bishop_tbl[bitRef].mask = bmask(bitRef);
    m_rook_tbl[bitRef].shift = 64 - RBits[bitRef];
    m_bishop_tbl[bitRef].shift = 64 - BBits[bitRef];
    mask = isRook ?  m_rook_tbl[bitRef].mask : m_bishop_tbl[bitRef].mask;
    bitCount = count_1s(mask);
    variationCount = 1 << bitCount;
    for (i = 0; i < variationCount; i++) {
      if (isRook) {
        m_rook_occupancy[bitRef][i] = 0ULL;
        m_rook_occupancy[bitRef][i] = set_occupancy(i, bitCount, mask);
      } else {
        m_bishop_occupancy[bitRef][i] = 0ULL;
        m_bishop_occupancy[bitRef][i] = set_occupancy(i, bitCount, mask);
      }
    }
  }
}

void Bitboard::_init_tables(int isRook) {
  U64 validMoves, mask;
  int variations, bitCount;
  int i, magicIndex;

  for (int bitRef = A1; bitRef < Squareend; ++bitRef) {
    mask = isRook ? m_rook_tbl[bitRef].mask : m_bishop_tbl[bitRef].mask;
    bitCount = count_1s(mask);
    variations = 1ULL << bitCount;

    for (i=0; i < variations; i++) {
      if (isRook) {
        validMoves = ratt(bitRef, m_rook_occupancy[bitRef][i]);
        magicIndex = m_rook_occupancy[bitRef][i] *
          m_rook_tbl[bitRef].magic >> m_rook_tbl[bitRef].shift;

        m_rook_table[bitRef][magicIndex] = validMoves;
      } else {
        validMoves = batt(bitRef, m_bishop_occupancy[bitRef][i]);
        magicIndex = m_bishop_occupancy[bitRef][i] *
          m_bishop_tbl[bitRef].magic >> m_bishop_tbl[bitRef].shift;

        m_bishop_table[bitRef][magicIndex] = validMoves;
      }
    }
  }
}

U64 Bitboard::get_non_attack_moves(int type, SquareIndices from) {
  if (type == bP)
    return m_b_pawn_non_attacks[from] & ~m_all_pieces;

  if (type == wP)
    return m_w_pawn_non_attacks[from] & ~m_all_pieces;

  return BLANK;
}

U64 Bitboard::get_piece_bitboard(int type) const {
  assert(Valid_piece(type));
  assert(m_pieces[type]);

  return m_pieces[type]->get_bitboard();
}

U64 Bitboard::get_piece_attacks(int type, SquareIndices from) {
  switch (type) {
    case bP:
      return m_b_pawn_attacks[from] & m_all_w_pieces;
    case wP:
      return m_w_pawn_attacks[from] & m_all_b_pieces;
    case bR:
    case wR:
      return rook_attacks(m_all_pieces, from);
    case bQ:
    case wQ:
      return queen_attacks(m_all_pieces, from);
    case bK:
    case wK:
      return m_king_attacks[from];
    case bB:
    case wB:
      return bishop_attacks(m_all_pieces, from);
    case bN:
    case wN:
      return m_knight_attacks[from];
    default:
      return ZERO;
  }
}

void Bitboard::gen_all_pawn_moves(int type, MoveList* moveList) {
  U64 dest_bitboard = BLANK, from_piece_pos_bb = m_pieces[type]->get_bitboard();
  int from = 0;
  Move mv;

  while (from_piece_pos_bb) {
    from = pop_1st_bit(&from_piece_pos_bb);
    mv.set_from(from);
    mv.set_piece(type);
    dest_bitboard = get_piece_attacks(type, SquareIndices(from));
    dest_bitboard &= ~(IS_BLACK(type) ? m_all_b_pieces : m_all_w_pieces);
    gen_all_captured_moves(dest_bitboard, mv, moveList);

    dest_bitboard = get_non_attack_moves(type, SquareIndices(from));
    dest_bitboard &= ~(IS_BLACK(type) ? m_all_b_pieces : m_all_w_pieces);
    gen_all_quiet_moves(dest_bitboard, mv, moveList);
  }
}

void Bitboard::gen_all_piece_moves(int type, MoveList* moveList) {
  U64 origin_bitboard = BLANK, dest_bitboard = BLANK;
  int from = 0;
  Move mv;

  origin_bitboard = m_pieces[type]->get_bitboard();
  while (origin_bitboard) {
    from = pop_1st_bit(&origin_bitboard);
    dest_bitboard =
      get_piece_attacks(type, SquareIndices(from));
    mv.set_from(from);
    mv.set_piece(type);
    dest_bitboard &= ~(IS_BLACK(type) ? m_all_b_pieces : m_all_w_pieces);
    gen_all_captured_moves(dest_bitboard, mv, moveList);
    gen_all_quiet_moves(dest_bitboard, mv, moveList);
  }
}

void Bitboard::gen_all_captured_moves(U64 dest, Move mv, MoveList* moveList) {
  dest &= IS_BLACK(mv.get_piece()) ? m_all_w_pieces : m_all_b_pieces;
  int to = 0, captured = 0;
  while (dest) {
    to = pop_1st_bit(&dest);
    mv.set_to(to);
    captured = get_piece_at_pos(to);
    mv.set_capture_piece(captured);
    add_captured_move(mv, moveList);
  }
}

void Bitboard::gen_all_quiet_moves(U64 dest, Move mv, MoveList* moveList) {
  dest &= IS_BLACK(mv.get_piece()) ? ~m_all_w_pieces : ~m_all_b_pieces;
  int to = 0;
  while (dest) {
    to = pop_1st_bit(&dest);
    mv.set_to(to);
    add_quiet_move(mv, moveList);
  }
}

void Bitboard::generate_all_moves(bool has_black_pieces, MoveList* moveList) {
  gen_all_piece_moves(has_black_pieces? bN : wN, moveList);
  gen_all_pawn_moves(has_black_pieces? bP : wP, moveList);
  gen_all_piece_moves(has_black_pieces? bB : wB, moveList);
  gen_all_piece_moves(has_black_pieces? bQ : wQ, moveList);
  gen_all_piece_moves(has_black_pieces? bK : wK, moveList);
  gen_all_piece_moves(has_black_pieces? bR : wR, moveList);
}

void Bitboard::clear_bit_at_player_pieces(bool is_black, int pos) {
  CLRBIT(is_black ? m_all_b_pieces : m_all_w_pieces, pos);
  CLRBIT(m_all_pieces, pos);
}

void Bitboard::set_bit_at_player_pieces(bool is_black, int pos) {
  SETBIT(is_black ? m_all_b_pieces : m_all_w_pieces, pos);
  SETBIT(m_all_pieces, pos);
}



void Bitboard::make_move_bb(int piece, int from, int to) {
  move(piece, from, to);
  ply++;
}

void Bitboard::undo_move(int piece, int piece_captured, int from, int to) {
  move(piece, from, to);
  put_piece_back(piece_captured, from);
  ply--;
}

void Bitboard::move(int piece, int from, int to) {
  if (!piece)
    return;

  m_pieces[piece]->make_move(from, to);
  clear_bit_at_player_pieces(IS_BLACK(piece), from);
  set_bit_at_player_pieces(IS_BLACK(piece), to);
  board_score -= pieces_score[piece][from];
  board_score += pieces_score[piece][to];
}

U64 Bitboard::get_all_w_bitboard() { return m_all_w_pieces; }
U64 Bitboard::get_all_b_bitboard() { return m_all_b_pieces; }
U64 Bitboard::get_all_pieces_bitboard() const { return m_all_pieces; }

void Bitboard::capture_piece(int captured, int pos) {
  if (!captured)
    return;

  m_pieces[captured]->clear_bit(pos);
  clear_bit_at_player_pieces(IS_BLACK(captured), pos);

  board_score -= m_pieces[captured]->get_value();
  board_score -= pieces_score[captured][pos];
}

void Bitboard::put_piece_back(int captured, int pos) {
  if (!captured)
    return;

  m_pieces[captured]->set_bit(pos);
  set_bit_at_player_pieces(IS_BLACK(captured), pos);

  board_score += pieces_score[captured][pos];
  board_score += m_pieces[captured]->get_value();
}

int Bitboard::evaluate_board() {
  return board_score;
}

int Bitboard::get_piece_at_pos(int pos) {
  U64 square = ONE << pos;

  for (int piece = bP; piece <= wK; ++piece) {
    if (square & m_pieces[piece]->get_bitboard())
      return piece;
  }

  return 0;
}

void Bitboard::update_killers(Move mv) {
  // Check whether this potential killer is a new one
  for (int i = 0; i < 2; ++i)
    if (killers[i][ply] == mv)
      return;

  killers[1][ply] = killers[0][ply];
  killers[0][ply] = mv;
}


void Bitboard::update_search_history(int piece, int to, int depth) {
  search_history[piece][to] += depth;
}

void Bitboard::add_quiet_move(Move quiet_mv, MoveList* move_list) {
  if (killers[0][ply] == quiet_mv) {
    quiet_mv.set_score(900000);
  } else if (killers[1][ply] == quiet_mv) {
    quiet_mv.set_score(800000);
  } else {
    quiet_mv.set_score(search_history[quiet_mv.get_piece()][quiet_mv.get_to()]);
  }

  move_list->push_back(quiet_mv);
}

void Bitboard::add_captured_move(Move capture_mv, MoveList* move_list) {
  capture_mv.set_score(
      MvvLvaScores[capture_mv.get_captured_piece()][capture_mv.get_piece()]
      + 1000000);
  move_list->push_back(capture_mv);
}

void Bitboard::add_en_pessant_move(Move ep_move, MoveList* move_list) {
  ep_move.set_score(105 + 1000000);
  move_list->push_back(ep_move);
}
