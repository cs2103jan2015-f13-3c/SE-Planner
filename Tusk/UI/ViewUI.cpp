#include <iostream>
#include "ViewUI.h"

ViewUI::ViewUI(void) {
}

ViewUI::~ViewUI(void) {
}

void ViewUI::inputUserCommand() {
	getline(std::cin, _userCommand);
}