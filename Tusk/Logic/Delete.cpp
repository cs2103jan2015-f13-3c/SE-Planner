#include "Delete.h"

Delete::Delete(void) {
}

Delete::~Delete(void) {
}

void Delete::executeCommand(std::vector<Task>& mainTaskList, Task& task, std::vector<Task> displayedTaskList) {
	int index;
	index = std::stoi(task.getTitle(), nullptr, 10);
	task = displayedTaskList[index - 1];
	
	for (int i = 0; i < mainTaskList.size(); i++) {
		if (mainTaskList[i].getTitle() == task.getTitle()) {
			mainTaskList.erase(mainTaskList.begin() + i);
		}
	}
}