#include "Input.h"

Input::Input(void) {
}

Input::~Input(void) {
}

void Input::inputCommand(std::string command) {
	_command = command;
}

std::string Input::getCommand() {
	return _command;
}