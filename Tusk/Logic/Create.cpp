#include "Create.h"

Create::Create(void) {
}

Create::~Create(void) {
}

void Create::execute(std::vector<Task>& taskList, Task task) {
	taskList.push_back(task);
}