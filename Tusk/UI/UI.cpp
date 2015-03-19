#include "UI.h"

UI::UI(void) {
	_viewUI = new ViewUI;
	_logic = new Logic;
}

UI::~UI(void) {
}

void UI::run() {
	std::string userCommand;
	std::string userInput;
	std::string result;
	
	while (userCommand != "exit") {
		userInput = _viewUI->getUserInput();
		userCommand = _viewUI->extractCommand(userInput);
		result = _logic->executeCommand(userInput);
		_viewUI->printResult(result);
	}
}