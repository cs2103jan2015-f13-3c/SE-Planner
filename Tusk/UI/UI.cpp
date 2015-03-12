#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::setInputedMessage(std::string message) {
	_input.setMessage(message);
}

std::string UI::getInputedMessage() {
	return _input.getMessage();
}

void UI::printMessage(Command command, std::vector<Task> taskList) {
	_output.printMessage(command, taskList);
}