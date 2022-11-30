#include "input/headers/text_input_player.h"

TextInputPlayer::TextInputPlayer(TextInputBase &t) : m_tib(t) {}
TextInputPlayer::~TextInputPlayer() {}

void TextInputPlayer::setup(BoardView &v) { 
  m_view.reset(&v);
}

void TextInputPlayer::update_turn(const PlayerInfo & p) {
  m_turn = p;
}

string TextInputPlayer::get_player_string_move(PlayerPosition &p) {
  std::cout << p.get_from_position() << std::endl;
  return m_tib.get_string_input();
}
