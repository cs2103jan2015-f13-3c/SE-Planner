#include "Command.h"

Command::Command(void) {
}

Command::~Command(void) {
}

void Command::inputCommand(std::string command) {
	_command = command;
}

std::string Command::getCommand() {
	return _command;
}