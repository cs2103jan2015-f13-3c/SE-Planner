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

class CreateTask : public Command {
private:
	Task _input;
public:
	CreateTask() {
	}

	CreateTask(Task input) {
		_input = input;
	}

	~CreateTask() {
	}

	void setInput(Task input) {
		_input = input;
	}

	void execute(vector<Task> &myVector) {
		myVector.push_back(_input);
	}
};

class DeleteTask : public Command {
private:
	int _index;
public:
	DeleteTask() {
		_index=0;
	}

	DeleteTask(int index) {
		_index = index;
	}

	~DeleteTask() {
	}

	void setIndex(int index) {
		_index = index;
	}

	void execute(vector<Task> &myVector) {
		if(_index>0&&_index<myVector.size()) {
			myVector.erase(myVector.begin()+_index-1);
		}
		// else error message
	}
 };