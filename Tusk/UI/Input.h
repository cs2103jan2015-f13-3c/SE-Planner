#pragma once

#include <string>

using namespace std;

class Input {
private:
	string _command;

public:
	Input(void);
	~Input(void);

	void inputCommand(string);
	string getCommand();
};