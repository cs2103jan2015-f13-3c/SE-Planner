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

void UI::outputMessage(Command command, std::vector<Task> taskList) {
	_output.outputMessage(command, taskList);
}