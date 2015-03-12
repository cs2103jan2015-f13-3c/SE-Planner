#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::inputCommand(std::string command) {
	_input.inputCommand(command);
}

std::string UI::getCommand() {
	return _input.getCommand();
}