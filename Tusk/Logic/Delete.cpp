#include "Delete.h"

Delete::Delete(void) {
}

Delete::~Delete(void) {
}

void Delete::execute() {
	int index;
	index = stoi(_information);

	Task task;
	task = _displayedTaskList[index - 1];

	std::vector<Task> taskList;
	taskList =_storage.getAllTask();

	for (int i = 0; i < taskList.size(); i++) {
		if (taskList[i].isTaskSame(task)) {
			taskList.erase(taskList.begin() + i);
		}
	}

	_storage.writeToFile(taskList);

	_result.push_back(task);
}