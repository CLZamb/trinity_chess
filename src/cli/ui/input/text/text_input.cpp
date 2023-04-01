#include "text_input.h"

TextInput::TextInput() : m_i_p(*this) {}
TextInput::~TextInput() {}

PlayerInput &TextInput::get_player_input() { return m_i_p; }
