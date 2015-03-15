#include "Add.h"

Add::Add(void) {
}

Add::~Add(void) {
}

void Add::executeAdd(std::vector<Task>& taskList, Task task) {
	taskList.push_back(task);
}