#include "Command.h"

Command::Command(void) {
}

Command::~Command(void) {
}

void Command::setCommandType(CommandType commandType) {
	_commandType = commandType;
}

CommandType Command::getCommandType() {
	return _commandType;
}