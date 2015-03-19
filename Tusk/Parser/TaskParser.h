#pragma once
#include "Task.h"
#include "Date.h"
#include "Time.h"

// special keywords
const std::string DATE_KEYWORD = "date:";
const std::string TIME_KEYWORD = "time:";

const std::string TIME_WITH_RANGE_KEY = "-";	// keys used to identify different taskTypes
const std::string DATE_WITH_RANGE_KEY = "-";
const std::string D_M_Y_KEY = ",";

enum TimeTypes{
	NO_TIME, DEFAULT_TIME, TIME_W_RANGE
};


enum DateTypes{
	NO_DATE, DEFAULT_DATE, DATE_W_RANGE
};

std::string _taskInput;

TaskType _taskType;
TimeTypes _timeType;
DateTypes _dateType;	

std::string _taskTime;
std::string _taskDate;
std::string _taskTitle;

class TaskParser
{
public:
	TaskParser(std::string);
	void parse();	

private:
	TaskType findTaskType();

	void setTime(TimeTypes timeType);
	void setDate(DateTypes dateType);
	bool isFound(std::string, std::string);
	std::string findTaskTitle();
};





