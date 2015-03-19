#pragma once

#include <iostream>
#include <string>

using namespace std;

class ViewUI {
public:
	ViewUI(void);
	~ViewUI(void);

	std::string getUserInput();
	std::string extractCommand(const string);
	void  printResult(const string);
};