#pragma once

#include "Common.h"
#include <string>

using namespace std;

//Hardcoded stuff put below this comment
enum {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_TURQOISE, DARK_RED, DARK_PINK, DARK_YELLOW, LIGHT_GREY, GREY, BLUE, GREEN, TURQOISE, RED, PINK, YELLOW, WHITE
};// enum the color for the use of the display text 

enum {
	CORNER_UL, CORNER_BL, CORNER_UR, CORNER_BR, HORIZONTAL, VERTICAL, UPPER_CENTER, LOWER_CENTER
};// enum the ASCII symbol for display  box 

//Corresponding ASCII values
static const char border[8] = {
	(const char) 201, (const char) 200, (const char) 187, (const char) 188, (const char) 205, (const char) 186, (const char) 203, (const char) 202
};

//CONSTANTS
static const int NUM_HELP_FIELDS = 5;
static const int NUM_COMMANDS = 10;

static const string COMMAND_PROMPT_ARROW = "> ";
static const string LEFT_BRACE = "[";
static const string RIGHT_BRACE = "]";
static const string DASH = " - ";
static const string DATE_DELIMITER = "/";
static const string TIME_DELIMITER = ":";

static const string SUCCESS_EXECUTE_COMMAND = "Command Successfully Executed";
static const string SUCCESS_EXIT = "Bye Bye :)";
static const string ERROR_INVALID_COMMAND = "Invalid Command. Please enter again\n";
static const string ERROR_VECTOR_EMPTY = "Empty\n";

static const string helpStringArray[NUM_COMMANDS][NUM_HELP_FIELDS] = {
		{"add\t", "", " [title]", " \tdate: DD/MM/YY - DD/MM/YY ", "\ttime: HHMM - HHMM\n" },
		{"search\t", "", " [title]", " \tdate: DD/MM/YY - DD/MM/YY ", "\ttime: HHMM - HHMM\n"},
		{"delete\t", " [index]\n", "", "", ""}, 
		{"done\t", " [index]\n", "", "", ""}, 
		{"edit\t", " [index]", " [title]", " \tdate: [new date]", " \ttime: [new time]\n"}, 
		{"display\t", "", " [today, tomorrow, overdue, all, DD/MM/YY]\n", "", ""}, 
		{"undo\n", "", "", "", ""},
		{"use\t", " [folderPath]\n", "", "", ""},
		{"where\n", "", "", "", ""},
		{"cls\n", "", "", "", ""}
	};

class UI
{
private:
	string _outputString;  
public:
	UI(void);
	~UI(void);

	void showExitMessage(void);
	void showSuccessMessage(void);
	

	// currently used function
	void showFailureMessage(void);
	bool printIfEmpty(const vector<Task>);
	void getMaxTitleAndInfoLength(const vector<Task>, int &, int &);
	void printUpperBorder(const int, const int);
	void printMainContent(const vector<Task>, const int, const int);
	void printLowerBorder(const int,const int);
	void showTaskList(vector<Task>);
	void showMessage(string);
	void showHelp();
	string getInput(void);

	//TESTING METHOD
	string getOutputString();
};

