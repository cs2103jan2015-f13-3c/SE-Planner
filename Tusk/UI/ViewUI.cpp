#include <iostream>
#include <sstream>
#include "ViewUI.h"

ViewUI::ViewUI(void) {
}

ViewUI::~ViewUI(void) {
}

std::string ViewUI::getUserInput() {
	string input = "";
	getline(std::cin, input);
	return input;
}

std::string ViewUI::extractCommand(const string input) {
	std::string userCommand;
	
	istringstream iss(input);
	iss >> userCommand;

	return userCommand;
}

void ViewUI::printResult(const string result){
	cout << result;
} 