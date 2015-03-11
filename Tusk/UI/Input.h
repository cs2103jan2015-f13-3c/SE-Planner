#pragma once

#include <string>

using namespace std;

class Input {
private:
	string _inputCommand;

public:
	Input(void);
	~Input(void);

	void inputCommand(string);
	string getInputCommand();
};