#pragma once

#include <string>

enum TaskType {
	TimedTask, Deadline, FloatingTask, RecurringTask
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