#include "input/headers/text_input_player.h"

TextInputPlayer::TextInputPlayer(TextInputBase &t) : m_tib(t) {}
TextInputPlayer::~TextInputPlayer() {}

void TextInputPlayer::setup(BoardView &v) { v.print(); }

void TextInputPlayer::update_turn(const PlayerInfo & p) {
  m_turn = p;
}

string TextInputPlayer::get_player_string_move(PlayerPosition &p) {
  std::cout << ">> ";
  return m_tib.get_string_input();
}
