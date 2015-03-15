#include "Output.h"
#include <sstream>


Output::Output(void) {
}

Output::~Output(void) {
}

void Output::setMessage(Command command, Task task, std::vector<Task> taskList) {
	//std::ostringstream message;

	switch (command.getCommandType()) {
	case ADD:
		_message =  MESSAGE_CREATED + task.getTitle() + "\n";
		break;
	case DISPLAY:
		_message = MESSAGE_DISPLAY;
		for (int i = 0; i < taskList.size(); i++) {
			_message = _message + (char)(i+49) + ". " + taskList[i].getTitle() + "\n";
		}
		break;
	case EDIT:
		_message = MESSAGE_UPDATED + task.getTitle() + "\n";
		break;
	case DELETE:
		_message = MESSAGE_DELETED + task.getTitle() + "\n";
		break;
	}
}

std::string Output::getMessage() {
	return _message;
}