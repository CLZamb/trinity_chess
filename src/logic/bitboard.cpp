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
  for (int Attacker = bP; Attacker <= wK; ++Attacker)
    for (int Victim = bP; Victim <= wK; ++Victim)
      MvvLvaScores[Victim][Attacker] =
        VictimScore[Victim] + 6 - (VictimScore[Attacker] / 10);
}

Piece* Bitboard::get_piece(int type) {
  return m_pieces[type];
}

void Bitboard::_init_nonsliders_attacks() {
  for (int sq = 0; sq < 64; sq++) {
    m_w_pawn_attacks[sq] = pawn_mask(sq, WHITE);
    m_b_pawn_attacks[sq] = pawn_mask(sq, BLACK);
    m_knight_attacks[sq] = knight_mask(sq);
    m_king_attacks[sq] = king_mask(sq);
  }
}

U64 Bitboard::pawn_mask(int sq, int side) {
  U64 pawn_mask = BLANK, left_attack = BLANK, right_attack = BLANK;
  U64 from_sq = ONE << sq;

  if (side == WHITE) {
    left_attack = bitUtility::shift<NORTH_WEST>(from_sq);
    right_attack = bitUtility::shift<NORTH_EAST>(from_sq);

    pawn_mask |= left_attack;
    pawn_mask |= right_attack;

  } else {  // side == BLACK
    left_attack = bitUtility::shift<SOUTH_EAST>(from_sq);
    right_attack = bitUtility::shift<SOUTH_WEST>(from_sq);

    pawn_mask |= left_attack;
    pawn_mask |= right_attack;
  }

  return pawn_mask;
}

U64 Bitboard::king_mask(int sq) {
  U64 king_mask = 0ULL;
  U64 from_sq = ONE << sq;

  king_mask |= bitUtility::shift<NORTH>(from_sq);
  king_mask |= bitUtility::shift<SOUTH>(from_sq);
  king_mask |= bitUtility::shift<EAST>(from_sq);
  king_mask |= bitUtility::shift<WEST>(from_sq);
  king_mask |= bitUtility::shift<NORTH_EAST>(from_sq);
  king_mask |= bitUtility::shift<NORTH_WEST>(from_sq);
  king_mask |= bitUtility::shift<SOUTH_EAST>(from_sq);
  king_mask |= bitUtility::shift<SOUTH_WEST>(from_sq);
  return king_mask;
}

U64 Bitboard::knight_mask(int sq) {
  U64 result = BLANK;
  U64 from_sq = ONE << sq;
  U64 shift = BLANK;

  shift = bitUtility::shift<SOUTH_SOUTH>(from_sq);
  shift = bitUtility::shift<WEST>(shift);
  if (shift & NOT_H_FILE)
    result |= shift & NOT_H_FILE;

  shift = bitUtility::shift<SOUTH_SOUTH>(from_sq);
  shift = bitUtility::shift<EAST>(shift);
  if (shift & NOT_A_FILE)
    result |= shift & NOT_A_FILE;

  shift = bitUtility::shift<SOUTH_WEST>(from_sq);
  shift = bitUtility::shift<WEST>(shift);
  if (shift & NOT_GH_FILE)
    result |= shift & NOT_GH_FILE;

  shift = bitUtility::shift<SOUTH_EAST>(from_sq);
  shift = bitUtility::shift<EAST>(shift);
  if (shift & NOT_AB_FILE)
    result |= shift & NOT_AB_FILE;

  shift = bitUtility::shift<NORTH_NORTH>(from_sq);
  shift = bitUtility::shift<EAST>(shift);
  if (shift & NOT_A_FILE)
    result |= shift & NOT_A_FILE;

  shift = bitUtility::shift<NORTH_NORTH>(from_sq);
  shift = bitUtility::shift<WEST>(shift);
  if (shift & NOT_H_FILE)
    result |= shift & NOT_H_FILE;

  shift = bitUtility::shift<NORTH_EAST>(from_sq);
  shift = bitUtility::shift<EAST>(shift);
  if (shift & NOT_AB_FILE)
    result |= shift & NOT_AB_FILE;

  shift = bitUtility::shift<NORTH_WEST>(from_sq);
  shift = bitUtility::shift<WEST>(shift);
  if (shift & NOT_GH_FILE)
    result |= shift & NOT_GH_FILE;

  return result;
}

U64 Bitboard::get_piece_bitboard(int type) const {
  assert(utils::check::is_valid_piece(type));
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

U64 Bitboard::get_non_attack_moves(int type, SquareIndices from) {
  if (type != bP && type != wP) return BLANK;

  U64 forward_one_sq = BLANK;
  U64 forward_two_sq = BLANK;
  U64 own_piece = m_pieces[type]->get_bitboard() & (ONE << from);
  const U64 free_squares = ~m_occupied;

  if (type == bP) {
    forward_one_sq = bitUtility::shift<SOUTH>(own_piece) & free_squares;
    forward_two_sq = bitUtility::shift<SOUTH>(forward_one_sq & ROWMASK[5]) & free_squares;
    return forward_one_sq | forward_two_sq;
  } else {  // white pawn
    forward_one_sq = bitUtility::shift<NORTH>(own_piece) & free_squares;
    forward_two_sq = bitUtility::shift<NORTH>(forward_one_sq & ROWMASK[2]) & free_squares;
  }

  return forward_one_sq | forward_two_sq;
}

void Bitboard::gen_all_piece_moves(int type, MoveList* moveList, bool quiet /*true*/) {
  U64 origin_bitboard = BLANK, dest_bitboard = BLANK;
  U64 side_bitboard =
    ~(utils::check::is_black_piece(type) ? m_all_b_pieces : m_all_w_pieces);
  int from = 0;
  Move mv;

  origin_bitboard = m_pieces[type]->get_bitboard();
  while (origin_bitboard) {
    from = bitUtility::pop_1st_bit(&origin_bitboard);
    dest_bitboard =
      get_piece_attacks(type, SquareIndices(from));
    mv.set_from(from);
    mv.set_piece(type);
    dest_bitboard &= side_bitboard;
    gen_all_captured_moves(dest_bitboard, mv, moveList);

    if (quiet)
      gen_all_quiet_moves(dest_bitboard, mv, moveList);
  }
}

void Bitboard::gen_all_captured_moves(U64 dest, Move mv, MoveList* moveList) {
  dest &=
    utils::check::is_black_piece(mv.get_piece()) ? m_all_w_pieces : m_all_b_pieces;
  int to = 0, captured = 0;
  while (dest) {
    to =  bitUtility::pop_1st_bit(&dest);
    mv.set_to(to);
    captured = get_piece_at_pos(to);
    mv.set_capture_piece(captured);
    add_captured_move(mv, moveList);
  }
}

void Bitboard::gen_all_quiet_moves(U64 dest, Move mv, MoveList* moveList) {
  dest &=
    utils::check::is_black_piece(mv.get_piece()) ? ~m_all_w_pieces : ~m_all_b_pieces;
  int to = 0;
  while (dest) {
    to = bitUtility::pop_1st_bit(&dest);
    mv.set_to(to);
    add_quiet_move(mv, moveList);
  }
}

void Bitboard::gen_pawn_black_moves(MoveList* move_list, bool quiet/*true*/) {
  gen_pawn_black_capture_moves(move_list);
  if (quiet)
    gen_pawn_black_quiet_moves(move_list);
}

void Bitboard::gen_pawn_black_quiet_moves(MoveList* move_list) {
  U64 own = m_pieces[bP]->get_bitboard();
  U64 forward_one_sq = bitUtility::shift<SOUTH>(own) & ~m_occupied;
  U64 forward_two_sq =
    bitUtility::shift<SOUTH>(forward_one_sq & ROWMASK[5]) & ~m_occupied;
  unsigned int to = 0;

  while (forward_one_sq) {
    to = bitUtility::pop_1st_bit(&forward_one_sq);
    add_quiet_move(Move(to - SOUTH, to, bP), move_list);
  }

  while (forward_two_sq) {
    to = bitUtility::pop_1st_bit(&forward_two_sq);
    add_quiet_move(Move(to - (SOUTH + SOUTH), to, bP), move_list);
  }
}

void Bitboard::gen_pawn_white_quiet_moves(MoveList* move_list) {
  U64 own = m_pieces[wP]->get_bitboard();
  U64 forward_one_sq = bitUtility::shift<NORTH>(own) & ~m_occupied;
  U64 forward_two_sq = bitUtility::shift<NORTH>(forward_one_sq & ROWMASK[2]) & ~m_occupied;
  unsigned int to = 0;

  while (forward_one_sq) {
    to = bitUtility::pop_1st_bit(&forward_one_sq);
    add_quiet_move(Move(to + SOUTH, to, wP), move_list);
  }

  while (forward_two_sq) {
    to = bitUtility::pop_1st_bit(&forward_two_sq);
    add_quiet_move(Move(to + (SOUTH + SOUTH), to, wP), move_list);
  }
}

void Bitboard::gen_pawn_black_capture_moves(MoveList* move_list) {
  unsigned int to = 0, captured = 0;
  U64 own = m_pieces[bP]->get_bitboard();
  U64 enemy = m_all_w_pieces;
  U64 captures = bitUtility::shift<SOUTH_EAST>(own) & enemy;

  while (captures) {
    to = bitUtility::pop_1st_bit(&captures);
    captured = get_piece_at_pos(to);
    add_captured_move(Move(to + NORTH_WEST, to, bP, captured), move_list);
  }

  captures = bitUtility::shift<SOUTH_WEST>(own) & enemy;
  while (captures) {
    to =  bitUtility::pop_1st_bit(&captures);
    captured = get_piece_at_pos(to);
    add_captured_move(Move(to + NORTH_EAST, to, bP, captured), move_list);
  }
}

void Bitboard::gen_pawn_white_capture_moves(MoveList* move_list) {
  U64 own = m_pieces[wP]->get_bitboard();
  U64 enemy = m_all_b_pieces;
  U64 captures = bitUtility::shift<NORTH_EAST>(own) & enemy;
  unsigned int to = 0, captured = 0;

  while (captures) {
    to = bitUtility::pop_1st_bit(&captures);
    captured = get_piece_at_pos(to);
    add_captured_move(Move(to + SOUTH_WEST, to, wP, captured), move_list);
  }

  captures = bitUtility::shift<NORTH_WEST>(own) & enemy;
  while (captures) {
    to = bitUtility::pop_1st_bit(&captures);
    captured = get_piece_at_pos(to);
    add_captured_move(Move(to + SOUTH_EAST, to, wP, captured), move_list);
  }
}

void Bitboard::generate_all_moves(bool has_black_pieces, MoveList* moveList) {
  if (has_black_pieces)
    generate_all_black_moves(moveList);
  else
    generate_all_white_moves(moveList);
}

void Bitboard::generate_all_black_moves(MoveList* moveList) {
  gen_all_piece_moves(bN, moveList);
  gen_pawn_black_capture_moves(moveList);
  gen_pawn_black_quiet_moves(moveList);
  gen_all_piece_moves(bB, moveList);
  gen_all_piece_moves(bR, moveList);
  gen_all_piece_moves(bQ, moveList);
  gen_all_piece_moves(bK, moveList);
}

void Bitboard::generate_all_white_moves(MoveList* moveList) {
  gen_all_piece_moves(wN, moveList);
  gen_pawn_white_capture_moves(moveList);
  gen_pawn_white_quiet_moves(moveList);
  gen_all_piece_moves(wB, moveList);
  gen_all_piece_moves(wR, moveList);
  gen_all_piece_moves(wQ, moveList);
  gen_all_piece_moves(wK, moveList);
}

void Bitboard::generate_all_cap_moves(bool has_black_pieces, MoveList* moveList) {
  gen_all_piece_moves(has_black_pieces? bN : wN, moveList, false);
  if (has_black_pieces)
    gen_pawn_black_capture_moves(moveList);
  else
    gen_pawn_white_capture_moves(moveList);
  gen_all_piece_moves(has_black_pieces? bB : wB, moveList, false);
  gen_all_piece_moves(has_black_pieces? bR : wR, moveList, false);
  gen_all_piece_moves(has_black_pieces? bQ : wQ, moveList, false);
  gen_all_piece_moves(has_black_pieces? bK : wK, moveList, false);
}

void Bitboard::set_piece_at_pos(int piece, SquareIndices square) {
  get_piece(piece)->set_bit(square);
  set_bit_at_player_pieces(utils::check::is_black_piece(piece), square);
}

void Bitboard::clear_search_history() {
  for (int i = 0; i < 13; ++i)
    for (int j = 0; j < utils::constant::ksquares; ++j)
      search_history[i][j] = 0;
}

void Bitboard::clear_killer_moves() {
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < utils::constant::kMaxDepth; ++j)
      killers[i][j].set_move(0);
}

void Bitboard::reset_ply() { ply = 0; }
int Bitboard::get_ply() { return ply; }
void Bitboard::increment_ply() { ply++; }
void Bitboard::deincrement_ply() { ply--; }

void Bitboard::clear_bit_at_player_pieces(bool is_black, SquareIndices pos) {
  bitUtility::clear_bit(is_black ? &m_all_b_pieces : &m_all_w_pieces, pos);
  bitUtility::clear_bit(&m_occupied, pos);
}

void Bitboard::set_bit_at_player_pieces(bool is_black, SquareIndices pos) {
  bitUtility::set_bit(is_black ? &m_all_b_pieces : &m_all_w_pieces, pos);
  bitUtility::set_bit(&m_occupied, pos);
}

void Bitboard::make_move_bb(int piece, SquareIndices from, SquareIndices to) {
  move(piece, from, to);
  ply++;
  assert(ply <= 64);
}

void Bitboard::undo_move(int piece, int captured,
    SquareIndices from, SquareIndices to) {
  move(piece, from, to);
  put_piece_back(captured, from);
  ply--;
}

void Bitboard::move(int piece, SquareIndices from, SquareIndices to) {
  if (!piece)
    return;

  m_pieces[piece]->make_move(from, to);
  clear_bit_at_player_pieces(utils::check::is_black_piece(piece), from);
  set_bit_at_player_pieces(utils::check::is_black_piece(piece), to);
}

U64 Bitboard::get_all_w_bitboard() { return m_all_w_pieces; }
U64 Bitboard::get_all_b_bitboard() { return m_all_b_pieces; }
U64 Bitboard::get_all_pieces_bitboard() const { return m_occupied; }

void Bitboard::capture_piece(int captured, SquareIndices pos) {
  if (!captured)
    return;

  m_pieces[captured]->clear_bit(pos);
  clear_bit_at_player_pieces(utils::check::is_black_piece(captured), pos);
}

void Bitboard::put_piece_back(int captured, SquareIndices pos) {
  if (!captured)
    return;

  m_pieces[captured]->set_bit(pos);
  set_bit_at_player_pieces(utils::check::is_black_piece(captured), pos);
}

int Bitboard::evaluate_board() {
  int board_score = 0;
  for (int pce = bP; pce <= wK; ++pce) {
    board_score += m_pieces[pce]->get_material_score();
    board_score += get_movility_score(pce);
  }
  return board_score;
}

int Bitboard::get_movility_score(int pce) {
  U64 temp_bb = m_pieces[pce]->get_bitboard();
  int score = 0;
  int pos = 0;

  while (temp_bb) {
    pos = bitUtility::pop_1st_bit(&temp_bb);
    score += pieces_score[pce][pos];
  }
  return score;
}

Piecetype Bitboard::get_piece_at_pos(int pos) {
  U64 square = ONE << pos;

  for (int piece = bP; piece <= wK; piece++) {
    if (square & m_pieces[piece]->get_bitboard())
      return static_cast<Piecetype>(piece);
  }

  return EMPTY;
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

void Bitboard::add_quiet_move(Move quiet, MoveList* move_list) {
  if (killers[0][ply] == quiet) {
    quiet.set_score(900000);
  } else if (killers[1][ply] == quiet) {
    quiet.set_score(800000);
  } else {
    quiet.set_score(search_history[quiet.get_piece()][quiet.get_to()]);
  }

  move_list->push_back(quiet);
}

void Bitboard::add_captured_move(Move capture, MoveList* move_list) {
  capture.set_score(
      MvvLvaScores[capture.get_captured_piece()][capture.get_piece()]
      + 1000000);
  move_list->push_back(capture);
}

void Bitboard::add_en_pessant_move(Move en_passant, MoveList* move_list) {
  en_passant.set_score(105 + 1000000);
  move_list->push_back(en_passant);
}
