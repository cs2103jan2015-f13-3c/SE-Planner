#include <iostream>
#include "Output.h"

Output::Output(void) {
}

Output::~Output(void) {
}

void Output::printMessage(Command command, std::vector<Task> taskList) {
	switch (command.getCommandType()) {
	case Create:
		_message = "[Created]" + taskList[0].getTitle() + "\n";
		break;
	case Read:
		_message = "[Display]\n";
		for (int i = 0; i < taskList.size(); i++) {
			_message = i + ". " + taskList[i].getTitle() + "\n";
		}
		break;
	case Update:
		_message = "[Updated]" + taskList[0].getTitle() + "\n";
		break;
	case Delete:
		_message = "[Deleted]" + taskList[0].getTitle() + "\n";
		break;
	}
	std::cout << _message;
}