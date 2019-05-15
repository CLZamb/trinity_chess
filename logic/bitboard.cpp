#include "bitboard.h"
Bitboard::Bitboard() {}

Bitboard::~Bitboard() {
  for (int i = EMPTY; i <= wK; i++)
    delete m_pieces[i];
}

void Bitboard::_init() {
  _init_MvvLva();
  _init_nonsliders_attacks();
  _init_pieces_table_values();
}

void Bitboard::reset_all_pieces_bitboard() {
  for (int piece = bP; piece <= wK; ++piece) {
    m_pieces[piece]->clear_bitboard();
  }

  m_all_w_pieces = m_all_b_pieces = m_occupied = BLANK;
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
  for (Attacker = bP; Attacker <= wK; ++Attacker)
    for (Victim = bP; Victim <= wK; ++Victim)
      MvvLvaScores[Victim][Attacker] =
        VictimScore[Victim] + 6 - (VictimScore[Attacker] / 10);
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


U64 Bitboard::get_piece_bitboard(int type) const {
  assert(Valid_piece(type));
  assert(m_pieces[type]);

  return m_pieces[type]->get_bitboard();
}

U64 Bitboard::get_piece_attacks(int type, SquareIndices from) {
  switch (type) {
    case bP:
    case wP:
      return get_pawn_attacks(type, from);
    case bR:
    case wR:
      return magic_bb.rook_attacks(m_occupied, from);
    case bQ:
    case wQ:
      return magic_bb.queen_attacks(m_occupied, from);
    case bK:
    case wK:
      return m_king_attacks[from];
    case bB:
    case wB:
      return magic_bb.bishop_attacks(m_occupied, from);
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
    from = magic_bb.pop_1st_bit(&from_piece_pos_bb);
    mv.set_from(from);
    mv.set_piece(type);
    dest_bitboard = get_pawn_attacks(type, SquareIndices(from));
    dest_bitboard &= ~(IS_BLACK(type) ? m_all_b_pieces : m_all_w_pieces);
    gen_all_captured_moves(dest_bitboard, mv, moveList);

    dest_bitboard = get_non_attack_moves(type, SquareIndices(from));
    dest_bitboard &= ~(IS_BLACK(type) ? m_all_b_pieces : m_all_w_pieces);
    gen_all_quiet_moves(dest_bitboard, mv, moveList);
  }
}

U64 Bitboard::get_pawn_attacks(int type, SquareIndices from) {
  if (type != bP && type != wP) return BLANK;

  if (type == bP)
    return get_black_pawn_attacks(from);

  return get_white_pawn_attacks(from);
}

U64 Bitboard::get_black_pawn_attacks(SquareIndices from) {
  return m_b_pawn_attacks[from] & m_all_w_pieces;
}

U64 Bitboard::get_white_pawn_attacks(SquareIndices from) {
  return m_w_pawn_attacks[from] & m_all_b_pieces;
}

U64 Bitboard::get_non_attack_moves(int type, SquareIndices from) {
  if (type != bP && type != wP) return BLANK;

  if (type == bP)
    return m_b_pawn_non_attacks[from] & ~m_occupied;

  return m_w_pawn_non_attacks[from] & ~m_occupied;
}

void Bitboard::gen_all_piece_moves(int type, MoveList* moveList) {
  U64 origin_bitboard = BLANK, dest_bitboard = BLANK;
  int from = 0;
  Move mv;

  origin_bitboard = m_pieces[type]->get_bitboard();
  while (origin_bitboard) {
    from = magic_bb.pop_1st_bit(&origin_bitboard);
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
    to = magic_bb.pop_1st_bit(&dest);
    mv.set_to(to);
    captured = get_piece_at_pos(to);
    assert(captured);
    mv.set_capture_piece(captured);
    add_captured_move(mv, moveList);
  }
}

void Bitboard::gen_all_quiet_moves(U64 dest, Move mv, MoveList* moveList) {
  dest &= IS_BLACK(mv.get_piece()) ? ~m_all_w_pieces : ~m_all_b_pieces;
  int to = 0;
  while (dest) {
    to = magic_bb.pop_1st_bit(&dest);
    mv.set_to(to);
    add_quiet_move(mv, moveList);
  }
}

void Bitboard::generate_all_moves(bool has_black_pieces, MoveList* moveList) {
  gen_all_piece_moves(has_black_pieces? bN : wN, moveList);
  gen_all_pawn_moves(has_black_pieces? bP : wP, moveList);
  gen_all_piece_moves(has_black_pieces? bB : wB, moveList);
  gen_all_piece_moves(has_black_pieces? bR : wR, moveList);
  gen_all_piece_moves(has_black_pieces? bQ : wQ, moveList);
  gen_all_piece_moves(has_black_pieces? bK : wK, moveList);
}

void Bitboard::set_piece_at_pos(int piece, int square) {
  get_piece(piece)->set_bit(square);
  set_bit_at_player_pieces(IS_BLACK(piece), square);
}

void Bitboard::clear_bit_at_player_pieces(bool is_black, int pos) {
  CLRBIT(is_black ? m_all_b_pieces : m_all_w_pieces, pos);
  CLRBIT(m_occupied, pos);
}

void Bitboard::set_bit_at_player_pieces(bool is_black, int pos) {
  SETBIT(is_black ? m_all_b_pieces : m_all_w_pieces, pos);
  SETBIT(m_occupied, pos);
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
U64 Bitboard::get_all_pieces_bitboard() const { return m_occupied; }

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
