#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::inputMessage() {
	_input.inputMessage();
}

std::string UI::getInputedMessage() {
	return _input.getMessage();
}