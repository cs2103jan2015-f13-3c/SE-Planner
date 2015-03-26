#include "Display.h"

Display::Display(void) {
}

Display::~Display(void) {
}

std::vector<Task> Display::execute() {
	_result = _storage.getAllTask();
	return _result;
}