#include "headers/uicontroller.h"

UIController::UIController() {}
UIController::~UIController() {}

void UIController::add_view(View view) {
  views.emplace(view.Get_name(), view);
}

void UIController::remove_view(const string& name) {
  if (!check_view_exist(name)) { return; }

  views.erase(name);
}

View& UIController::get_view(const string& name) {
  if (!check_view_exist(name))
    exit(EXIT_FAILURE); 

  return views.at(name);
}

void UIController::print_view(const string& key) {
  if (!check_view_exist(key)) { return; }

  views.at(key).print();
}

void UIController::change_active_view(const string& name) {
  if (!check_view_exist(name)) { return; }

  active_view_key = name;
}

bool UIController::check_view_exist(const string& key) {
  if (views.find(key) != views.end()) return true;
  cout << key << " view does not exists" << endl;

  return false;
}

