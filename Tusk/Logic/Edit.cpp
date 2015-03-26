#include "Edit.h"

#include <assert.h>
Edit::Edit(void) {
}

Edit::~Edit(void) {
}

void Edit::setDisplayedTaskList(std::vector<Task> displayedTaskList) {
	_displayedTaskList = displayedTaskList;
}

void Edit::setIndex(int index) {
	_index = index;
}

void Edit::setTask(Task task) {
	_task = task;
}

std::vector<Task> Edit::execute() {
	Task task;
	task = _displayedTaskList[_index-1];


	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	for (int i = 0; i < taskList.size(); i++) {
		if (taskList[i].getTitle() == task.getTitle()) {
			taskList[i] = task;
		}
	}

	_storage.writeToFile(taskList);

	_result.push_back(task);
	return _result;
}