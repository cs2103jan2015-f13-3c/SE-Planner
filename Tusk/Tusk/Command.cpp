#include "Command.h"

Command::Command(void) {
}

Command::~Command(void) {
}

void Command::inputCommandType(CommandType commandType) {
	_commandType = commandType;
}

CommandType Command::getCommandType() {
	return _commandType;
}