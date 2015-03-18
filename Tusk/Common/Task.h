//Authored by Ang Yoong Zhen
//
//Pre-condition: None
//Post-condition: Task will be stored in various variables which
//                can be retrived and editied individually when needed.
//
//Sample usage:
//	Task task;
//
//	To store/edit task as abctask:
//	task.setTaskType(FLOATINGTASK);
//	task.setTitle("abctask");
//
//	To retrive task's details:
//	task.getTaskType();
//	task.getTitle();

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

	bool _isDone;

public:
	Task(void);
	~Task(void);


	void setTaskType(TaskType);
	void setTitle(std::string);

	void setStartingTime(Time);
	void setEndingTime(Time);

	void setStartingDate(Date);
	void setEndingDate(Date);

	void setIsDone(bool);


	TaskType getTaskType();
	std::string getTitle();

	Time getStartingTime();
	Time getEndingTime();

	Date getStartingDate();
	Date getEndingDate();

	bool getIsDone();
};