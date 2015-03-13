#include <iostream>
#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::setInputedMessage() {
	std::string message;
	std::cin >> message;
	_input.setMessage(message);
}

void UI::setOutputedMessage(Command command, Task task, std::vector<Task> taskList) {
	_output.setMessage(command, task, taskList);
}

std::string UI::getInputedMessage() {
	return _input.getMessage();
}

void UI::printOutputedMessage() {
	std::cout << _output.getMessage();
}