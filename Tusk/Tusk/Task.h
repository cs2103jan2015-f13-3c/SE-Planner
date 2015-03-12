#pragma once

#include <string>

class Task {
private:
	std::string _task;

public:
	Task(void);
	~Task(void);

	void inputTask(std::string);

	std::string getTask();
};