#ifndef MESSAGES_H
#define MESSAGES_H
#include "Idisplay.h"
#include "../../include/common/headers/common.h"
#include "../headers/message_state.h"
#include "../headers/section.h"

enum Msg : int {
  no_message,
  welcome,
  chooseColor,
  chooseStartOption,
  gameOver
};

class Messages : public Displayable {
 public:
    Messages();
    ~Messages();
    void draw();
    void set_message(MessageState* message_state);

    MessageState* get_play_or_quit();
    MessageState* get_players_options();
    MessageState* get_game_over();
    MessageState* get_choose_color();
    MessageState* get_no_message();

 private:
    No_message m_no_message;
    Play_or_quit m_start_or_quit;
    Players_options m_players_options;
    Game_over m_game_over;
    Choose_color m_choose_color;
    MessageState* p_current_state;
    shared_ptr<Section> p_main = std::make_shared<Section>("main", 1);
};

#endif /* MESSAGES_H */
