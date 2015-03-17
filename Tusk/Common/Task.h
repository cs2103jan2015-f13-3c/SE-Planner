#pragma once

#include <string>
#include "Time.h"
#include "Date.h"

enum TaskType {
	TIMEDTASK, DEADLINE, FLOATINGTASK
};

class Task {
private:
	TaskType _taskType;
	std::string _title;

	Time _startingTime;
	Time _endingTime;

	Date _startingDate;
	Date _endingDate;

public:
	Task(void);
	~Task(void);


	void setTaskType(TaskType);
	void setTitle(std::string);

	void setStartingTime(Time);
	void setEndingTime(Time);

	void setStartingDate(Date);
	void setEndingDate(Date);


	TaskType getTaskType();
	std::string getTitle();

	Time getStartingTime();
	Time getEndingTime();

	Date getStartingDate();
	Date getEndingDate();
};