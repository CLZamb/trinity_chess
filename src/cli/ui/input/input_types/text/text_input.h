#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H

#include "text_input_base.h"

class TextInput : public TextInputBase {
 public:
  TextInput();
  virtual ~TextInput();

 private:
  // bool check_valid_option(vector<int>& keys, const int key) {
  //   return std::find(keys.begin(), keys.end(), key) != keys.end();
  // };
};

#endif /* CONSOLE_INPUT_H */
