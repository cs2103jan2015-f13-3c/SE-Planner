#include <iostream>
#include "ViewUI.h"

ViewUI::ViewUI(void) {
}

ViewUI::~ViewUI(void) {
}

std::string ViewUI::inputUserCommand() {
	std::string userCommand;
	getline(std::cin, userCommand);
	return userCommand;
}