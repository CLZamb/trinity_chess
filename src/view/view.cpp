#include "headers/view.h"

using std::flush;

View::View(string name) { this->name = name; }

void View::print() { 
  cout << window_view << flush; 
}

string View::Get_name() { return name; }

string View::name{ "" };

void View::draw() {}
