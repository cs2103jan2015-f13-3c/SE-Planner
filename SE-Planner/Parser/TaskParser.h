#pragma once

#include <string>
#include "Task.h"
#include "TimeParser.h"
#include "DateParser.h"

const std::string DEFAULT_TIME = "2359";

class TaskParser {
private:
	Task _task;
	TimeParser _timeParser;
	DateParser _dateParser;

public:
	TaskParser(void);
	~TaskParser(void);

	Task getTask();

	bool parseTask(std::string);
};