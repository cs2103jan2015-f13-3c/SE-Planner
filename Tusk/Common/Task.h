#pragma once

#include <string>

enum TaskType {
	TIMEDTASK, DEADLINE, FLOATINGTASK, RECURRINGTASK
};

class Task {
private:
	TaskType _taskType;
	std::string _title;

public:
	Task(void);
	~Task(void);
	
	void setTaskType(TaskType);
	void setTitle(std::string);

	TaskType getTaskType();
	std::string getTitle();
};