#include "headers/board.h"

Board::Board() {
  // parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  // parser_fen("r1bqkbnr/pppppppp/2n5/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  // parser_fen("r1bqkbnr/pppppppp/2n5/4p3/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq e3 0 1");
  // parser_fen("rnbqkb1r/pppp1ppp/5n2/4p3/4P3/2N5/PPPP1PPP/R1BQKBNR b KQkq e3 0 1");
  // parser_fen("r2qr1k1/1bp1bppp/p1np1n2/1p2p3/3PP3/1BP2N1P/PP3PP1/RNBQR1K1 w - - 1 10");
  // parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 64; ++i)
    delete p_squares[i];

  for (auto p : m_pieces)
    delete p;

  m_pieces.clear();
}

void Board::_init(Pane* board_drawing) {
  m_drawing = board_drawing;
  m_drawing->set_top(
      " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");

  p_main = std::make_unique<Section>("board", 40);
  board_drawing->add_section(p_main);

  m_drawing->set_bottom({
      " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃",
      " ┃    A        B        C        D        E        F        G       H     ┃",
      " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"});

  create_board_squares();
  create_pieces();
  parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  // parser_fen("r2qr1k1/1bp1bppp/p1np1n2/1p2p3/3PP3/1BP2N1P/PP3PP1/RNBQR1K1 w - - 1 10");
  // parser_fen("r1bqkbnr/pppppppp/2n5/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
  // movement_controller._init(turn->has_black_pieces());
}

void Board::set_checkmate_true() {
  checkmate = true;
}

bool Board::is_checkmate() {
  return checkmate;
}

void Board::make_move(string pl_move) {
}

void Board::set_players(Player* player1, Player* player2) {
  this->player1 = player1;
  this->player2 = player2;
  this->player1->set_opponent(this->player2);
  this->player2->set_opponent(this->player1);
  this->turn = player1;
}

// void Board::move_squares(Piece* piece, SquareIndices from, SquareIndices to) {
  // if (!piece || !get_square_at_pos(from) || !get_square_at_pos(to))
  //   return;
  //
  // get_square_at_pos(from)->clear_square();
  // get_square_at_pos(to)->set_piece(piece);
// }

// Piece* Board::get_piece_at_square(int pos) {
  // if (!get_square_at_pos(pos))
  //   return nullptr;
  //
  // return get_square_at_pos(pos)->get_piece();
// }
// PlayerMove Board::get_next_move() { return turn->get_next_move(); }
// Player* Board::get_active_player() {  return turn; }
// Player* Board::get_opponent() { return turn->get_opponent(); }

char Board::left_border(int row, int col) {
  return (col + 1) % 3 ? ' ' :  ('0' + row + 1);
}

Board::Square* Board::get_square_at_pos(int pos) { return p_squares[pos]; }

void Board::create_pieces() {
  if (!m_pieces.empty())
    m_pieces.empty();

  Piecetype pct = EMPTY;
  for (int piece_type = bP; piece_type <= wK; ++piece_type) {
    pct = Piecetype(piece_type);
    m_pieces[piece_type] = new Piece(pct);
  }
}

void Board::create_board_squares() {
  create_empty_squares_drawing();
  char squareColor = 'w';

  int position = 0;
  // need to be ordered upside down
  for (int row = 7; row >= 0; --row) {
    for (int col = 0; col < 8; ++col) {
      position = row * 8 + col;
      if (squareColor == 'b') {
        squareColor = 'w';
        p_squares[position] = new Square(*this, &wSquare, false);
      } else {
        squareColor = 'b';
        p_squares[position] = new Square(*this, &bSquare, true);
      }
    }
    squareColor = squareColor == 'b' ? 'w' : 'b';
  }
}

void Board::create_empty_squares_drawing() {
  wSquare = *Drawing("BaseWhiteSquare").get_drawing();
  bSquare = *Drawing("BaseBlackSquare").get_drawing();
}

void Board::parser_fen(string fen) {
  // m_bb.reset_all_pieces_bitboard();
  SquareIndices square = A1;
  int rank = 7;
  int file = 0;
  int piece;
  //
  for (const char& c : fen) {
    piece = utils::get_square_index_from_char_key(c);
    if (piece) {
      square = static_cast<SquareIndices>(rank * 8 + file);
      // m_bb.set_piece_at_pos(piece, square);
      add_to_board(piece, square);
      file++;

    } else if (is_number(c)) {
      file += (c - '0');

    } else if (c == '/') {
      rank--;
      file = 0;
    }

    if (rank < 0) break;
  }
}

void Board::add_to_board(int type, SquareIndices position) {
  get_square_at_pos(position)->set_piece(type);
}

bool Board::is_number(char c) {
  return c >= '0' && c <= '8';
}

// void Board::undo_last_move() {
//   // movement_controller.undo_last_move();
// }
//
// void Board::make_move(PlayerMove p_mv) {
//   Move move = p_mv.get_move();
//   movement_controller.move_piece(move);
//
//   string played_move = utils::get_piece_str_name(move.get_piece())
//     + "-" +  p_mv.get_input();
//
//   turn->save_played_moves(played_move);
// }
//
// bool Board::is_valid_move(Move mv) {
//   // return movement_controller.is_valid_move(mv);
// }
//
// bool Board::get_checkmate() {
//   // return movement_controller.get_checkmate();
// }
//
// Movement* Board::get_movement() {
//   // return &movement_controller;
// }
//
// void Board::update_killers(Move mv) {
//   // m_bb.update_killers(mv);
// }
//
// void Board::update_search_history(int piece, int to, int depth) {
//   // m_bb.update_search_history(piece, to, depth);
// }
//
// void Board::capture_piece(Move mv, SquareIndices pos) {
//   // Piecetype captured_piece = mv.get_captured_piece();
//   //
//   // capture_piece_bit(captured_piece, pos);
//   // turn->save_captured_pieces(utils::get_piece_str_name(captured_piece));
// }
//
// // void Board::change_turn() { turn = turn->get_opponent(); }
// void Board::capture_piece_bit(int piece_captured, SquareIndices pos) {
//   // m_bb.capture_piece(piece_captured, pos);
// }
//
// void Board::undo_move(int piece, int piece_captured, SquareIndices from, SquareIndices to) {
//   // m_bb.undo_move(piece, piece_captured, from, to);
// }

// void Board::clear_killer_moves() { m_bb.clear_killer_moves(); }
// void Board::clear_search_history() { m_bb.clear_search_history(); }
// void Board::reset_ply() { m_bb.reset_ply(); }
// int Board::get_ply() { return m_bb.get_ply(); }
// void Board::increment_ply() { return m_bb.increment_ply(); }
// void Board::deincrement_ply() { return m_bb.deincrement_ply(); }
//
// U64 Board::get_piece_attacks(int type, int from) {
//   return m_bb.get_piece_attacks(type, SquareIndices(from));
// }
//
// U64 Board::get_non_attack_moves(int type, int from) {
//   return m_bb.get_non_attack_moves(type, SquareIndices(from));
// }
//
// U64 Board::get_own_pieces_occ(bool is_black) {
//   if (is_black) return m_bb.get_all_b_bitboard();
//
//   return  m_bb.get_all_w_bitboard();
// }
//
// U64 Board::get_all_pieces_bitboard() const {
//   return m_bb.get_all_pieces_bitboard();
// }
//
// U64 Board::get_piece_bitboard(int piece) const {
//   return m_bb.get_piece_bitboard(piece);
// }
//
// Piecetype Board::get_piece_at(int pos) {
//   return m_bb.get_piece_at_pos(pos);
// }
//
// int Board::evaluate_board() { return m_bb.evaluate_board(); }

//
// Board::Square
Board::Square::Square(const Board& parent, box* emtpySqDrawing, bool blackBox)
    : m_board(parent),
      p_empty_square_drawing(emtpySqDrawing),
      p_cur_drawing(emtpySqDrawing),
      m_is_black_square(blackBox) {}

Board::Square::~Square() {}

void Board::Square::set_piece(int type) {
  p_cur_drawing = m_board.m_pieces[type]->get_drawing(m_is_black_square);
}

void Board::Square::clear_square() {
  p_cur_drawing = p_empty_square_drawing;
  // p_piece = nullptr;
}

char* Board::Square::at(int i) { return p_cur_drawing->content[i]; }
bool Board::Square::is_black_square() { return m_is_black_square; }
// Piece* Board::Square::get_piece() { return this->p_piece; }
box* Board::Square::get_current_drawing() { return p_cur_drawing; }
// end Board::Square

void Board::draw_board() {
  int row_counter = 0;
  string row_drawing = "";
  // need to be print upside down so that the bottom begins at row 0
  // for each board row
  for (int row = 7; row >= 0; --row) {
    // for each box row
    for (int k = 0; k < box::kRowSize; ++k, row_counter++) {
      row_drawing = "";

      row_drawing += left_border(row, k);
      row_drawing += "┃";
      // for each board column
      for (int col = 0; col < 8; col++) {
        row_drawing += p_squares[(row * 8) + col]->at(k);
      }

      row_drawing += "┃";
      *p_main->get_section().at(row_counter) = row_drawing;
    }
  }
}

Player* Board::get_turn() {
  return turn;
}

Player* Board::get_player_1() {
  return player1;
}

Player* Board::get_player_2() {
  return player2;
}
