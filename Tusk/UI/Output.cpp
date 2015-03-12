#include <iostream>
#include "Output.h"

Output::Output(void) {
}

Output::~Output(void) {
}

void Output::printMessage(Command command, Task task, std::vector<Task> taskList) {
	switch (command.getCommandType()) {
	case CREATE:
		_message = "[Created]" + task.getTitle() + "\n";
		break;
	case READ:
		_message = "[Display]\n";
		for (int i = 0; i < taskList.size(); i++) {
			_message = i + ". " + taskList[i].getTitle() + "\n";
		}
		break;
	case UPDATE:
		_message = "[Updated]" + task.getTitle() + "\n";
		break;
	case DELETE:
		_message = "[Deleted]" + task.getTitle() + "\n";
		break;
	}
	std::cout << _message;
}