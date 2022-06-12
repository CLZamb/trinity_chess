#include "headers/keyboard_input.h"

termios KeyboardInput::old;
termios KeyboardInput::current;

using std::cout;

KeyboardInput::KeyboardInput() {
  tcgetattr(STDIN_FILENO, &old);
  current = old;
  current.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &current);

  m_event.set_type(InputEvent::None);
}

KeyboardInput::~KeyboardInput() { 
  tcsetattr(STDIN_FILENO, TCSANOW, &old); 
}

void KeyboardInput::get_player_string_move() {
  select_menu_option();
}

void KeyboardInput::select_menu_option() {
  m_event.set_type(InputEvent::KeyPressed);
  bool selected = false;
  InputKeys::Key key_pressed = InputKeys::quit;

  while (!selected) {
    key_pressed = InputKeys::Key(fgetc(stdin));
    switch (key_pressed) {
      case InputKeys::quit:
      case InputKeys::Quit:
        exit(EXIT_SUCCESS);
      case InputKeys::ENTER:
        selected = true;
        notify_key_pressed(key_pressed);
        break;
      case InputKeys::ARROW_KEY:
        notify_key_pressed(get_arrow_key_pressed());
        break;
      default:
        cout << "Invalid key, please use arrow keys, select with enter!\n";
        break;
    }
  }
}

void KeyboardInput::notify_key_pressed(const InputKeys::Key &key_pressed) {
  m_event.set_pressed_key(key_pressed);
  notify_input_event();
}

InputKeys::Key KeyboardInput::get_arrow_key_pressed() {
  if (fgetc(stdin) != InputKeys::LEFT_BRACKET) return InputKeys::Quit;

  InputKeys::Key key_pressed = key_pressed = InputKeys::Key(fgetc(stdin));
  return key_pressed;
}

void KeyboardInput::update_listener(InputObserver *observer) {
  if (!observer) return;

  p_observer = observer;
  m_event.set_type(InputEvent::KeyboardSetup);
  notify_input_event();
}

void KeyboardInput::notify_input_event() {
  if (p_observer)
    p_observer->handle_input_event(m_event);
}
