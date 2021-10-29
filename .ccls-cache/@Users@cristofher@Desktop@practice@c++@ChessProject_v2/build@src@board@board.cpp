#include "headers/board.h"

Board::Board(IMoveValidation& m): Displayable(), m_move_validator(m) {
  // parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
}

Board::~Board() {
  // Free each array and sub-array
  for (int i = 0; i < 64; ++i)
    delete p_squares[i];

  for (auto p : m_pieces)
    delete p;
}

void Board::_init() {
  p_top_section = std::make_unique<Section>("top", 1);
  p_main = std::make_unique<Section>("board", 40);
  p_bottom_section = std::make_unique<Section>("bottom", 3);

  m_drawing.add_section(p_top_section);
  m_drawing.add_section(p_main);
  m_drawing.add_section(p_bottom_section);

  p_top_section->set_content_at_index(
       " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓", 0);
  p_bottom_section->set_content({
       " ┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃",
       " ┃    A        B        C        D        E        F        G       H     ┃",
       " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"});

  create_board_squares();
  create_pieces();
  parser_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
}

void Board::set_checkmate_true() {
  checkmate = true;
}

bool Board::is_checkmate() {
  return checkmate;
}

bool Board::is_legal_move(Move& m) {
  Piece* piece = get_piece_at_square(m.get_from());
  Piece* captured_piece = get_piece_at_square(m.get_to());

  if (!piece) return false;
  if (check_piece_belongs_to_current_player(piece)) {
    return false;
  }

  if (captured_piece) {
    m.set_capture_piece(captured_piece->get_type_and_color());
  }

  return piece->is_legal_move(m);
}

bool Board::check_piece_belongs_to_current_player(Piece* piece) {
  return piece->is_black() != turn->has_black_pieces();
}

void Board::make_move(Move mv) {
  SquareIndices from = mv.get_from();
  SquareIndices to = mv.get_to();
  Piece* piece = get_piece_at_square(from);

  move_piece_to_square(piece, from, to);
}

void Board::set_players(
    shared_ptr<Player> player1, shared_ptr<Player> player2) {
  this->player1 = player1;
  this->player2 = player2;
  this->player1->set_opponent(this->player2);
  this->player2->set_opponent(this->player1);
  this->turn = player1;
}

void
Board::move_piece_to_square(Piece* pc, SquareIndices from, SquareIndices to) {
  if (!pc || !get_square_at_pos(from) || !get_square_at_pos(to))
    return;

  get_square_at_pos(from)->clear_square();
  get_square_at_pos(to)->set_piece(pc);
}

Piece* Board::get_piece_at_square(int pos) {
  Square* square = get_square_at_pos(pos);

  if (!square)
    return nullptr;

  return square->get_piece();
}

char Board::left_border(int row, int col) {
  return (col + 1) % 3 ? ' ' :  ('0' + row + 1);
}


void Board::create_pieces() {
  if (!m_pieces.empty())
    m_pieces.empty();

  Piecetype pct = EMPTY;
  // for (int piece_type = bP; piece_type <= wK; ++piece_type) {
  //   pct = Piecetype(piece_type);
  //   m_pieces[piece_type] = new Piece(pct);
  // }
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
        p_squares[position] = new Square(&wSquare, false);
      } else {
        squareColor = 'b';
        p_squares[position] = new Square(&bSquare, true);
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

  add_to_board(wP, A2);
  add_to_board(bP, A7);
  // for (const char& c : fen) {
  //   piece = utils::get_square_index_from_char_key(c);
  //   if (piece) {
  //     square = static_cast<SquareIndices>(rank * 8 + file);
  //     // m_bb.set_piece_at_pos(piece, square);
  //     add_to_board(piece, square);
  //     file++;
  //
  //   } else if (is_number(c)) {
  //     file += (c - '0');
  //
  //   } else if (c == '/') {
  //     rank--;
  //     file = 0;
  //   }
  //
  //   if (rank < 0) break;
  // }
}

void Board::add_to_board(int type, SquareIndices position) {
  get_square_at_pos(position)->set_piece(m_pieces[type]);
}

bool Board::is_number(char c) {
  return c >= '0' && c <= '8';
}

Square* Board::get_square_at_pos(int pos) { return p_squares[pos]; }

void Board::draw() {
  int row_counter = 0;
  string row_drawing = "";
  // need to be print upside down so that the bottom begins at row 0
  for (int row = 7; row >= 0; --row) {
    for (int k = 0; k < box::kRowSize; ++k, row_counter++) {
      row_drawing = "";

      row_drawing += left_border(row, k);
      row_drawing += "┃";

      for (int col = 0; col < 8; col++) {
        row_drawing += p_squares[(row * 8) + col]->at(k);
      }

      row_drawing += "┃";
      p_main->set_content_at_index(row_drawing, row_counter);
    }
  }
}

std::shared_ptr<Player> Board::get_turn() {
  return turn;
}

std::shared_ptr<Player> Board::get_opponent() {
  return turn->get_opponent();
}

std::shared_ptr<Player> Board::get_player_1() {
  return player1;
}

std::shared_ptr<Player> Board::get_player_2() {
  return player2;
}

void Board::update_turn(GameTurn::players pl_turn) {
  m_turn = pl_turn;

  if (m_turn == GameTurn::player_1)
    this->turn = player1;
  else
    this->turn = player2;
}
