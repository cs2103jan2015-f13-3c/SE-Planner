#pragma once

#include <string>

class Input {
private:
	std::string _command;

public:
	Input(void);
	~Input(void);

	void inputCommand(std::string);

	std::string getCommand();
};