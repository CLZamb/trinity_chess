#include "text_input_player.h"

TextInputPlayer::TextInputPlayer(TextInputBase &t) : m_text_input(t) {}
TextInputPlayer::~TextInputPlayer() {}

void TextInputPlayer::setup(BoardView &v) { 
  m_view.reset(&v);
}

void TextInputPlayer::update_turn(const PlayerInfo & p) {
  m_turn = p;
}

string TextInputPlayer::get_player_string_move(PlayerPosition &p) {
  p.get_from_position();
  return m_text_input.get_string_input();
}
