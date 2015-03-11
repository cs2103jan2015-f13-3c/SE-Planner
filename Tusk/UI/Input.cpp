#include "Input.h"

Input::Input(void) {
}

Input::~Input(void) {
}

void Input::inputCommand(string command) {
	_command = command;
}

string Input::getCommand() {
	return _command;
}