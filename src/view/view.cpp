#include "headers/view.h"

using std::cout;
using std::flush;

View::View(string name) { this->name = name; }

void View::print() { cout << window_view << flush; }

string View::get_name() { return name; }

string View::name{""};

void View::draw() {}