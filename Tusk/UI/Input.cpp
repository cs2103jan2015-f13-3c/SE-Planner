#include "Input.h"

Input::Input(void) {
}

Input::~Input(void) {
}

void Input::setMessage(std::string message) {
	_message = message;
}

std::string Input::getMessage() {
	return _message;
}