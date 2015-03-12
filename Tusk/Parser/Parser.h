#pragma once
#include "Command.h"
#include "Task.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const std::string CREATE_COMMAND = "create";
const std::string UPDATE_COMMAND = "update";
const std::string READ_COMMAND = "read";
const std::string DELETE_COMMAND = "delete";

class Parser {
	private:
	Task _task;
	Command _command;

	Command createNewCommand(CommandType);
	Task createNewTask(TaskType, std::string);
	
	std::string removeFirstWord(std::string);
	std::string processString(std::string);

	TaskType findTaskType(std::string);

	std::pair <TaskType, std::string> extractTaskFromInput(std::string);

	std::string getKeyword(std::string);
	std::string	removeKeyword(std::string);

	bool searchForCreateCommand(std::string);
	bool searchForUpdateCommand(std::string);
	bool searchForReadCommand(std::string);
	bool searchForDeleteCommand(std::string);

	CommandType extractCommandFromInput(std::string);

	public:
	Parser(void);
	~Parser(void);

	Command getCommand();
	Task getTask();

	std::pair <Command, Task> parseUserInput(std::string);
	
	
};