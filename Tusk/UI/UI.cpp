#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::inputCommand(string command) {
	_input.inputCommand(command);
}

string UI::getCommand() {
	return _input.getCommand();
}