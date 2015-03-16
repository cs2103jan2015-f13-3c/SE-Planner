#pragma once

#include <string>
#include "Time.h"
#include "Date.h"

enum TaskType {
	TIMEDTASK, DEADLINE, FLOATINGTASK, RECURRINGTASK
};

class Task {
private:
	TaskType _taskType;
	std::string _title;
	int _numberOfRepeat;

	Time _startingTime;
	Time _endingTime;

	Date _startingDate;
	Date _endingDate;

public:
	Task(void);
	~Task(void);
	

	void setTaskType(TaskType);
	void setTitle(std::string);
	void setNumberOfRepeat(int);

	void setStartingTime(Time);
	void setEndingTime(Time);

	void setStartingDate(Date);
	void setEndingDate(Date);


	TaskType getTaskType();
	std::string getTitle();
	int getNumberOfRepeat();

	Time getStartingTime();
	Time getEndingTime();

	Date getStartingDate();
	Date getEndingDate();
};