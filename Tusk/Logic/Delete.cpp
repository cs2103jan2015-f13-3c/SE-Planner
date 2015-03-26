#include "Delete.h"

Delete::Delete(void) {
}

Delete::~Delete(void) {
}

std::vector<Task> Delete::execute() {
	int index;
	index = stoi(_information);

	Task task;
	task = _displayedTaskList[index-1];

	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	for (int i = 0; i < taskList.size(); i++) {
		if (task.getTitle() == taskList[i].getTitle()) {
			taskList.erase(taskList.begin() + i);
		}
	}

	_storage.writeToFile(taskList);

	_result.push_back(task);
	return _result;
}

void Delete::setDisplayedTaskList(std::vector<Task> displayedTaskList) {
	_displayedTaskList = displayedTaskList;
}

void Delete::setInformation(std::string information) {
	_information = information;
}