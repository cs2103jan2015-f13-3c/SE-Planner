#pragma once

#include <string>

class ViewUI {
private:
	std::string _userCommand;

public:
	ViewUI(void);
	~ViewUI(void);

	void inputUserCommand();
};