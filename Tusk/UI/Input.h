#pragma once

#include <string>

class Input {
private:
	std::string _message;

public:
	Input(void);
	~Input(void);

	void inputMessage();
	std::string getMessage();
};