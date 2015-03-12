#include "Delete.h"

Delete::Delete(void) {
}

Delete::~Delete(void) {
}

void Delete::execute(std::vector<Task>& taskList, Task& task) {
	int index;
	index = std::stoi(task.getTitle(), nullptr, 10);
	task = taskList[index - 1];
	taskList.erase(taskList.begin() + index - 1);
}