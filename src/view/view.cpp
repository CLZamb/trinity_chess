#include "headers/view.h"

using std::cout;
using std::flush;

View::View(string n) { this->name = n; }

void View::print() { 
  // system(CLEAR);
  cout << _window << flush; 
}

string View::get_name() { return name; }

string View::name{""};

void View::draw() {}
