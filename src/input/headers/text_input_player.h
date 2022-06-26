#ifndef TEXT_INPUT_PLAYER_H
#define TEXT_INPUT_PLAYER_H

#include "input/headers/input_type.h"
#include "input/headers/text_input_base.h"

class TextInputPlayer : public PlayerInput {
  public:
    TextInputPlayer(TextInputBase&);
    virtual ~TextInputPlayer();
    void update_turn(const PlayerInfo&) override;
    void setup(BoardView& v) override;
    string get_player_string_move(PlayerPosition& p) override;
  private:
    TextInputBase &m_tib;
    std::unique_ptr<BoardView> m_view;
    PlayerInfo m_turn;
};

#endif /* TEXT_INPUT_PLAYER_H */
