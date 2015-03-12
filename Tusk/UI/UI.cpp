#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::inputMessage(std::string message) {
	_input.inputMessage(message);
}

std::string UI::getInputedMessage() {
	return _input.getMessage();
}