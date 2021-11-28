#include "headers/view.h"


// View::View()  {}
View::View(string name) {
  this->name = name;
}

void View::print() {
  cout << window_view << endl;
}

string View::Get_name() {
  return name;
}

string View::name{ "" }; // initializer

    // static string name;
