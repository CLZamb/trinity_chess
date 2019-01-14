#ifndef MESSAGES_H
#define MESSAGES_H
#include "display.h"

class Messages : public Display {
private:
public:
  Messages();
  ~Messages() {}

  static char *welcomeMessage;
  static char *startMessage;
  static char *gameOver;
  static string m_nextMessage;
  void print();
  // void rabiit():
};

#endif /* MESSAGES_H */
