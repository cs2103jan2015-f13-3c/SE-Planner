#include "Command.h"

Command::Command(CommandType commandType) {
	_commandType = commandType;
}

Command::~Command(void) {
}

CommandType Command::getCommandType() {
	return _commandType;
}