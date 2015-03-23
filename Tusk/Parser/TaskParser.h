#pragma once
#include "Task.h"
#include "TaskTimeParser.h"
#include "TaskDateParser.h"

class TaskParser{
public:
	TaskParser(std::string);
	void parse();	
	Date getDate();
	Date getDateStart();
	Date getDateEnd();
	Time getTimeStart();
	Time getTimeEnd();
	Time getTime();
	Task getTask();



private:
	TaskDateParser _dateParser;
	TaskTimeParser _timeParser;
	std::string _taskInput;

	TaskType _taskType;
	std::string _taskTitle;

	TaskType findTaskType();

	bool isFound(std::string, std::string);
	std::string findTaskTitle();

	std::string removeDate(std::string);
	std::string removeTime(std::string);
	
};
