#ifndef MESSAGES_H
#define MESSAGES_H
#include "Idisplay.h"
#include "../../../include/common/headers/common.h"

enum Msg : int {
  No_message,
  Welcome,
  ChooseColor,
  ChooseStartOption,
  GameOver
};

class Messages : public IDisplay {
  public:
    Messages();
    ~Messages() {}

    void print();

    static Msg m_nextMessage;
  private:
    static const char* p_welcome_message;
    static const char* p_options_message;
    static const char* p_game_over;
    static const char* p_choose_color_message;
};

#endif /* MESSAGES_H */
