#include "Delete.h"

Delete::Delete(void) {
}

Delete::~Delete(void) {
}

void Delete::executeDelete(std::vector<Task>& storedTaskList, Task& task, std::vector<Task> displayedTaskList) {
	int index;
	index = std::stoi(task.getTitle(), nullptr, 10);
	task = displayedTaskList[index - 1];

	for (int i = 0; i < storedTaskList.size(); i++) {
		if (storedTaskList[i].getTitle() == task.getTitle()) {
			storedTaskList.erase(storedTaskList.begin() + i);
		}
	}
}