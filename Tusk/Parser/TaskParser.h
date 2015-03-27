#pragma once
#include "../Common/Task.h"
#include "../Parser/TaskTimeParser.h"
#include "../Parser/TaskDateParser.h"

class TaskParser{
public:
	TaskParser(std::string,bool);
	void parse();	
	Date getDate();
	Date getDateStart();
	Date getDateEnd();
	Time getTimeStart();
	Time getTimeEnd();
	Time getTime();
	Task getTask();
	std::string getTaskIndex();



private:
	TaskDateParser _dateParser;
	TaskTimeParser _timeParser;
	std::string _taskInput;
	std::string _taskIndex;
	bool _hasIndex;
	std::string trimLeadingSpaces(std::string);
	TaskType _taskType;
	std::string _taskTitle;

	TaskType findTaskType();
	std::string findTaskIndex();

	bool isFound(std::string, std::string);
	std::string findTaskTitle();

	std::string removeDate(std::string);
	std::string removeTime(std::string);
	
};
