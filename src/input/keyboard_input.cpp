#include "headers/keyboard_input.h"

termios KeyboardInput::old;
termios KeyboardInput::current;

string KeyboardInput::hide_cursor  = "\x1b[?25l";
string KeyboardInput::show_cursor  = "\x1b[?25h";

using std::cout;

KeyboardInput::KeyboardInput() {
  set_terminal_new_attributes();
  m_event.set_event_type(InputEvent::None);
  m_event.set_type(InputEvent::Keyboard);
}

KeyboardInput::~KeyboardInput() { 
  reset_terminal_configuration();
}

void KeyboardInput::reset_terminal_configuration() {
  write(STDOUT_FILENO, show_cursor.c_str(), 6);

  tcsetattr(STDIN_FILENO, TCSANOW, &old); 
}

void KeyboardInput::set_terminal_new_attributes() {
  write(STDOUT_FILENO, hide_cursor.c_str(), 6);

  tcgetattr(STDIN_FILENO, &old);
  current = old;
  current.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &current);
}

void KeyboardInput::get_player_string_move() {
  select_menu_option();
}

void KeyboardInput::select_menu_option() {
  bool selected = false;
  m_event.set_event_type(InputEvent::KeyPressed);

  while (!selected) {
    switch (InputKeys::Key(fgetc(stdin))) {
      case InputKeys::quit:
      case InputKeys::Quit:
        reset_terminal_configuration();
        exit(EXIT_SUCCESS);
        break;
      case InputKeys::ENTER:
        selected = true;
        notify_key_pressed(InputKeys::ENTER);
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

void KeyboardInput::update_input_event_listener(InputObserver *observer) {
  if (!observer) return;

  p_observer = observer;
  m_event.set_event_type(InputEvent::Setup);
  notify_input_event();
}

void KeyboardInput::notify_input_event() {
  if (!p_observer) return;

  p_observer->handle_input_event(m_event);
}

void KeyboardInput::dispatch_event(const InputEvent& event) {
  m_event.set_event_type(event.get_event_type());
  notify_input_event();
}
