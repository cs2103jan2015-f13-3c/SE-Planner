#include "Command.h"

Command::Command(void) {
}

Command::~Command(void) {
}

std::vector<Task> Command::execute() {
	return _result;
}