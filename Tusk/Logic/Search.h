#pragma once

#include "command.h"

class Search: public Command {
private:
	std::string _information;

public:
	Search(void);
	~Search(void);

	std::vector<Task> execute();
	void setInformation(std::string);
};