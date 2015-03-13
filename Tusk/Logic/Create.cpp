#include "Create.h"

Create::Create(void) {
}

Create::~Create(void) {
}

void Create::executeCommand(std::vector<Task>& taskList, Task task) {
	taskList.push_back(task);
}