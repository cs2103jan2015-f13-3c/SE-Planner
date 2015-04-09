#pragma once

#include "Common.h"
#include <string>

using namespace std;

//Hardcoded stuff put below this comment
enum {
	CORNER_UL, CORNER_BL, CORNER_UR, CORNER_BR, HORIZONTAL, VERTICAL, UPPER_CENTER, LOWER_CENTER
};

//Corresponding ASCII values
static const char border[8] = {
	(const char) 201, (const char) 200, (const char) 187, (const char) 188, (const char) 205, (const char) 186, (const char) 203, (const char) 202
};

class UI
{
public:
	UI(void);
	~UI(void);

	void showExitMessage(void);
	void showSuccessMessage(void);
	

	// currently used function
	void showFailureMessage(void);
	void showTaskList(vector<Task>);
	void showMessage(string);
	void showHelp();
	string getInput(void);
};

