#include "input/headers/text_input_player.h"

TextInputPlayer::TextInputPlayer(TextInputBase &t) : m_tib(t) {}
TextInputPlayer::~TextInputPlayer() {}

void TextInputPlayer::update_turn(const PlayerInfo &p) {}

void TextInputPlayer::setup(BoardView &v) { v.print(); }

string TextInputPlayer::get_player_string_move(BoardView &v, HumanPlayer &p) {
  return m_tib.get_string_input();
}
