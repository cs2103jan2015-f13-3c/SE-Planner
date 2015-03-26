#include "Display.h"

Display::Display(void) {
}

Display::~Display(void) {
}

void Display::execute() {
	_result = _storage.getAllTask();
}