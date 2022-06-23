#ifndef TEXT_INPUT_PLAYER_H
#define TEXT_INPUT_PLAYER_H

#include "input/headers/input_type.h"
#include "input/headers/text_input_base.h"

class TextInputPlayer : public PlayerInput {
  public:
    TextInputPlayer(TextInputBase&);
    virtual ~TextInputPlayer();
    void update_turn(const PlayerInfo& p);
    void setup(BoardView& v);
    string get_player_string_move(BoardView& v, HumanPlayer& p);
  private:
    TextInputBase &m_tib;
    std::unique_ptr<BoardView> m_view;
};

#endif /* TEXT_INPUT_PLAYER_H */
