#include "Edit.h"

Edit::Edit(void) {
}

Edit::~Edit(void) {
}

void Edit::execute() {
	int index;
	index = stoi(_information);

	Task task;
	task = _displayedTaskList[index - 1];

	std::vector<Task> taskList;
	taskList = _storage.getAllTask();

	for (int i = 0; i < taskList.size(); i++) {
		if (taskList[i].isTaskSame(task)) {
			taskList[i] = _task;
		}
	}

	_storage.writeToFile(taskList);

	_result.push_back(_task);
}