#include "UI.h"

UI::UI(void) {
}

UI::~UI(void) {
}

void UI::run() {
	std::string userCommand;
	while (userCommand != "exit") {
		userCommand = _viewUI.inputUserCommand();
	}
}