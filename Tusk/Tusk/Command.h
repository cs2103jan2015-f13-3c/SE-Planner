#pragma once

#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

enum CommandType {
	Create, Read, Update, Delete
};

class Command {
private:
	CommandType _commandType;

public:
	Command(void);
	~Command(void);

	void inputCommandType(CommandType);

	CommandType getCommandType();

	void execute(vector<Task> &);
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