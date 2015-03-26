#include "Edit.h"

Edit::Edit(void) {
}

Edit::~Edit(void) {
}

std::vector<Task> Edit::execute() {
	int index;
	index = stoi(_information);

	Task task;
	task = _displayedTaskList[index-1];

	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	for (int i = 0; i < taskList.size(); i++) {
		if (task.getTitle() == taskList[i].getTitle()) {
			taskList[i] = task;
		}
	}

	_storage.writeToFile(taskList);

	_result.push_back(task);
	return _result;
}

void Edit::setTask(Task task) {
	_task = task;
}

void Edit::setDisplayedTaskList(std::vector<Task> displayedTaskList) {
	_displayedTaskList = displayedTaskList;
}

void Edit::setInformation(std::string information) {
	_information = information;
}