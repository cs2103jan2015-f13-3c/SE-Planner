#pragma once

#include "Input.h"
#include "Output.h"

class UI {
private:
	Input _input;
	Output _output;

public:
	UI(void);
	~UI(void);

	void setInputedMessage(std::string);
	std::string getInputedMessage();

	void printMessage(Command, std::vector<Task>);
};