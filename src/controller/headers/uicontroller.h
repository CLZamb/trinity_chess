#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <iostream>
#include "view/headers/view.h"
#include "graphics/headers/window.h"
#include <unordered_map>

/*! \class uicontroller
 *  \brief Brief class description
 *
 *  Detailed description
 */
class UIController {
public:
  UIController();
  virtual ~UIController();

  void change_active_view(const string& name);
  void add_view(View view);
  void remove_view(const string& name);
  View& get_view(const string& name);
  void print_view(const string& key);

private:
  string active_view_key = "";
  std::unordered_map<std::string, View> views;
  bool check_view_exist(const string& key);
};

#endif /* UICONTROLLER_H */
