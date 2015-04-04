#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "Logic.h"
#include "Task.h"
#include "Parser.h"

using namespace std;

const string SUCCESS_ADD = "Successfully added";
const string SUCCESS_DELETE = "Successfully deleted";
const string SUCCESS_EDIT = "Successfully edited";
const string SUCCESS_SEARCH = "Search results: ";
const string SUCCESS_EXIT = "Exiting Tusk";
const string ERROR_GENERAL = "Operation could not be carried out";

class UI {
private:
	Logic *_logic;

public:
	UI(void);
	~UI(void);

	void run();
	/*
	void startCounter();
	double getCounter();
	*/
	std::string inputUserCommand();
	void printResult(const vector<Task>, const CommandType);
	void vectorToString(vector<Task>);
};