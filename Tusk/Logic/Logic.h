#pragma once

#include <iostream>
#include <vector>
#include "Task.h"
#include "Command.h"
#include "Parser.h"
#include "Storage.h"

using namespace std;

class Logic {
private:
	vector<Task> _myVector;
	Storage *_myStorage;
	Parser *_myParser;

	CommandType _commandType;
	string _taskTitle;
	TaskType _taskType;
	
public:
	Logic(void);
	~Logic(void);

	//Temp function to create placeholder
	Task getTask();
	
	void initializeVector();

	void getCommandData(string);

	void executeCommand();

	Task generateTask();

	int convertToInteger(const string);

	void createTask();

	void deleteTask();
};