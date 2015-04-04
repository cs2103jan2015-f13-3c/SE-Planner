#pragma once

#include <string>
#include "MyTime.h"
#include "Date.h"

enum TaskType {
	TIMEDTASK, DEADLINE, FLOATINGTASK
};

class Task {
private:
	TaskType _taskType;
	std::string _description;
	bool _isDone;

	MyTime _startingTime;
	MyTime _endingTime;

	Date _startingDate;
	Date _endingDate;

public:
	Task(void);
	~Task(void);

	void setTaskType(TaskType);
	void setDescription(std::string);
	void setIsDone(bool);
	
	void setStartingTime(MyTime);
	void setEndingTime(MyTime);

	void setStartingDate(Date);
	void setEndingDate(Date);

	TaskType getTaskType();
	std::string getDescription();
	bool getIsDone();

	MyTime getStartingTime();
	MyTime getEndingTime();

	Date getStartingDate();
	Date getEndingDate();

	bool isSameAs(Task);
};