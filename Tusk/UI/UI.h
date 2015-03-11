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

	void inputCommand(string);
	string getCommand();
};