#include "Add.h"

Add::Add(void) {
}

Add::~Add(void) {
}

void Add::execute() {
	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	taskList.push_back(_task);
	_storage.writeToFile(taskList);

	_result.push_back(_task);
}