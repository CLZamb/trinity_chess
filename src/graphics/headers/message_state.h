#ifndef MESSAGESTATE_H
#define MESSAGESTATE_H

#include "game_drawings.hpp"

class Messages;
class MessageState {
 public:
  explicit MessageState(Messages* msg);
  virtual ~MessageState();
  const char* get_message() { return p_message; }
 protected:
  Messages* p_messages = nullptr;
  const char* p_message = nullptr;
};

struct Play_or_quit : public MessageState {
  explicit Play_or_quit(Messages* msg);
};

struct Players_options : public MessageState {
  explicit Players_options(Messages* msg);
};

struct Game_over: public MessageState {
 public:
  explicit Game_over(Messages* msg);
};

struct Choose_color : public MessageState {
 public:
  explicit Choose_color(Messages* msg);
};

struct No_message : public MessageState {
 public:
  explicit No_message(Messages* msg);
};

#endif /* MESSAGESTATE_H */
