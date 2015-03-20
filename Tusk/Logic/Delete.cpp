#include "Delete.h"

Delete::Delete(void) {
}

Delete::~Delete(void) {
}

void Delete::setIndex(int index) {
	_index = index;
}

void Delete::setDisplayedTaskList(std::vector<Task> displayTaskList) {
	_displayedTaskList = displayTaskList;
}

std::vector<Task> Delete::execute() {
	Task task;
	task = _displayedTaskList[_index-1];

	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	for (int i = 0; i < taskList.size(); i++) {
		if (taskList[i].getTitle() == task.getTitle()) {
			taskList.erase(taskList.begin() + _index);
		}
	}

	_storage.writeToFile(taskList);


	_result.push_back(task);
	return _result;
}