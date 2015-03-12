#pragma once

#include <string>

class Task {
private:
	std::string _title;

public:
	Task(void);
	~Task(void);

	void inputTitle(std::string);

	std::string getTitle();
};