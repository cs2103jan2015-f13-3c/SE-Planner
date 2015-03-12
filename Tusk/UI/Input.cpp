#include <iostream>
#include "Input.h"

Input::Input(void) {
}

Input::~Input(void) {
}

void Input::inputMessage() {
	std::cin >> _message;
}

std::string Input::getMessage() {
	return _message;
}