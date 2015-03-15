#pragma once

#include <string>

enum TaskType {
	TIMEDTASK, DEADLINE, FLOATINGTASK, RECURRINGTASK
};

class Task {
private:
	TaskType _taskType;
	std::string _title;
	std::string _startingTime;
	std::string _endingTime;

public:
	Task(void);
	~Task(void);
	
	void setTaskType(TaskType);
	void setTitle(std::string);
	void setStartingTime(std::string);
	void setEndingTime(std::string);

	inline TaskType getTaskType();
	inline std::string getTitle();
	inline std::string getStartingTime();
	inline std::string getEndingTime();
};