#pragma once
#include "Task.h"
#include "TaskTimeParser.h"

// special keywords
const std::string DATE_KEYWORD = "date:";

const std::string DATE_WITH_RANGE_KEY = "-";
const std::string D_M_Y_KEY = ",";

enum DateTypes{
	NO_DATE, DEFAULT_DATE, DATE_W_RANGE
};


class TaskParser{
public:
	TaskParser(std::string);
	void parse();	

private:
	std::string _taskInput;

	TaskType _taskType;
	//TimeTypes _timeType;
	DateTypes _dateType;	

	//std::string _taskTime;
	std::string _taskDate;
	std::string _taskTitle;


	TaskType findTaskType();

	void setDate(DateTypes dateType);
	bool isFound(std::string, std::string);
	std::string findTaskTitle();
};
