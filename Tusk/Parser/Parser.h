#pragma once
#include "Command.h"
#include "Task.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

const std::string CREATE_COMMAND = "/c ";
const std::string UPDATE_COMMAND = "/u ";
const std::string READ_COMMAND = "/v ";
const std::string DELETE_COMMAND = "/r ";

class Parser {
	private:
	Task _task;
	Command _command;

	public:
	Parser(void);
	~Parser(void);
	Command getCommand();
	Task getTask();

	Command createNewCommand(CommandType);
	Task createNewTask(TaskType, std::string);
	std::pair <Command, Task> parseUserInput(std::string);

	std::string processString(std::string);

	TaskType findTaskType(std::string);

	std::pair <TaskType, std::string> extractTaskFromInput(std::string);

	bool searchForCreateCommand(std::string);
	bool searchForUpdateCommand(std::string);
	bool searchForReadCommand(std::string);
	bool searchForDeleteCommand(std::string);

	CommandType extractCommandFromInput(std::string);
};