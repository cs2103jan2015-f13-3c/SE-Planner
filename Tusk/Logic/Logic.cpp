#include "Logic.h"

Logic::Logic(void) {
}

Logic::~Logic(void) {
}

void Logic::executeCommand(Command command, std::vector<Task> mainTaskList) {
	switch (command.getCommandType()) {
	case CREATE:
		_create.execute(mainTaskList, _task);
		break;
	case READ:
		break;
	case UPDATE:
		break;
	case DELETE:
		_delete.execute(mainTaskList, _task, _displayedTaskList);
		break;
	}
}