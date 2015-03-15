#pragma once
#include "Command.h"
#include "Task.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const std::string CREATE_COMMAND = "add";
const std::string UPDATE_COMMAND = "edit";
const std::string READ_COMMAND = "display";
const std::string DELETE_COMMAND = "delete";

// special keywords
const std::string DATE_KEYWORD = "date:";
const std::string TIME_KEYWORD = "time:";

const std::string TIME_WITH_RANGE_KEY = "-";	// keys used to identify different taskTypes
const std::string DATE_WITH_RANGE_KEY = "-";
const std::string D_M_Y_KEY = ",";

// available TaskTypes:
// FLOATINGTASK(add [])															+default
// DEADLINE(add [] 1. date time 2. date)										+date
// TIMEDTASK(add [] 1. date: time: []-[] 2. date: []-[] time: []-[] )			+time_range
// RECURRINGTASK (add [] 1. date: [],[],[] Time: []-[] 2. date: time: []-[] )	+DMY

// available CommandTypes:
// CREATE, READ, UPDATE, DELETE
// TODO: commandTypes header not updated

class Parser {

private:
	Task _task;
	TaskType _taskType;
	Command _command;

	Command createNewCommand(CommandType);
	Task createNewTask(TaskType, std::string);

	std::string removeFirstWord(std::string);
	std::string processString(std::string);

	TaskType findTaskType(std::string);

	std::pair <TaskType, std::string> extractTaskFromInput(std::string);

	std::string getKeyword(std::string);
	std::string	removeKeyword(std::string);

	void trimLeadingSpaces(std::string&);

	bool searchForCreateCommand(std::string);
	bool searchForUpdateCommand(std::string);
	bool searchForReadCommand(std::string);
	bool searchForDeleteCommand(std::string);

	CommandType extractCommandFromInput(std::string);

public:
	Parser(void);
	~Parser(void);

	std::pair <Command, Task> parseUserInput(std::string);

};