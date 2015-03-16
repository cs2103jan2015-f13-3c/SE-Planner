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

	Time _startingTime;
	Time _endingTime;

	Date _startingDate;
	Date _endingDate;

	int _numberOfRepeat;

public:
	Task(void);
	~Task(void);
	

	void setTaskType(TaskType);
	void setTitle(std::string);

	void setStartingTime(Time);
	void setEndingTime(Time);

	void setStartingDate(Date);
	void setEndingDate(Date);

	void setNumberOfRepeat(int);


	TaskType getTaskType();
	std::string getTitle();

	Time getStartingTime();
	Time getEndingTime();

	Date getStartingDate();
	Date getEndingDate();

	int getNumberOfRepeat();
};