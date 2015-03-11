#include "Input.h"

Input::Input(void) {
}

Input::~Input(void) {
}

void Input::inputCommand(string inputedCommand) {
	_inputedCommand = inputedCommand;
}

string Input::getInputedCommand() {
	return _inputedCommand;
}